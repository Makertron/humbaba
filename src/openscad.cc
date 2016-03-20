/*
 *  OpenSCAD (www.openscad.org)
 *  Copyright (C) 2009-2011 Clifford Wolf <clifford@clifford.at> and
 *                          Marius Kintel <marius@kintel.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  As a special exception, you have permission to link this program
 *  with the CGAL library and distribute executables, as long as you
 *  follow the requirements of the GNU GPL in regard to all of the
 *  software in the executable aside from CGAL.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "openscad.h"
#include "node.h"
#include "module.h"
#include "modcontext.h"
#include "value.h"
#include "export.h"
#include "builtin.h"
#include "printutils.h"
#include "handle_dep.h"
#include "feature.h"
#include "parsersettings.h"
#include "rendersettings.h"
#include "PlatformUtils.h"
#include "LibraryInfo.h"
#include "nodedumper.h"
#include "stackcheck.h"
#include "CocoaUtils.h"
#include "FontCache.h"

#include <string>
#include <vector>
#include <fstream>

#ifdef ENABLE_CGAL
#include "CGAL_Nef_polyhedron.h"
#include "cgalutils.h"
#endif

#include "csgterm.h"
#include "CSGTermEvaluator.h"
#include "CsgInfo.h"

#include <sstream>

#include "Camera.h"
#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include "boosty.h"

#ifdef __APPLE__
#include "AppleEvents.h"
  #ifdef OPENSCAD_UPDATER
    #include "SparkleAutoUpdater.h"
  #endif
#endif

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

// Socket includes =================

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// ==================================

namespace po = boost::program_options;
namespace fs = boost::filesystem;
namespace Render { enum type { GEOMETRY, CGAL, OPENCSG, THROWNTOGETHER }; };
using std::string;
using std::vector;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using boost::is_any_of;

std::string commandline_commands;
std::string CURRENTDIR;


#define QUOTE(x__) # x__
#define QUOTED(x__) QUOTE(x__)

std::string openscad_shortversionnumber = QUOTED(OPENSCAD_SHORTVERSION);
std::string openscad_versionnumber = QUOTED(OPENSCAD_VERSION);

std::string openscad_displayversionnumber = 
#ifdef OPENSCAD_COMMIT
  QUOTED(OPENSCAD_VERSION)
  " (git " QUOTED(OPENSCAD_COMMIT) ")";
#else
  QUOTED(OPENSCAD_SHORTVERSION);
#endif

std::string openscad_detailedversionnumber =
#ifdef OPENSCAD_COMMIT
  openscad_displayversionnumber;
#else
  openscad_versionnumber;
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
static void version()
{
	PRINTB("OpenSCAD version %s", TOSTRING(OPENSCAD_VERSION));
	exit(0);
}

/**
 * Initialize gettext. This must be called after the appliation path was
 * determined so we can lookup the resource path for the language translation
 * files.
 */
void localization_init() {
	fs::path po_dir(PlatformUtils::resourcePath("locale"));
	std::string locale_path(po_dir.string());

	if (fs::is_directory(locale_path)) {
		setlocale(LC_ALL, "");
		bindtextdomain("openscad", locale_path.c_str());
		bind_textdomain_codeset("openscad", "UTF-8");
		textdomain("openscad");
	} else {
		PRINT("Could not initialize localization.");
	}
}


std::string process_request(std::string text)
{
	try
	  {
		
		PlatformUtils::registerApplicationPath(CURRENTDIR);
		
		parser_init();
		localization_init();

		Tree tree;
		GeometryEvaluator geomevaluator(tree);
	
		// Top context - this context only holds builtins
		ModuleContext top_ctx;
		top_ctx.registerBuiltin();
		FileModule *root_module;
		ModuleInstantiation root_inst("group");
		AbstractNode *root_node;
		AbstractNode *absolute_root_node;
		shared_ptr<const Geometry> root_geom;
		
		std::string parentpath(CURRENTDIR);
	   
		root_module = parse(text.c_str(), parentpath.c_str(), false);
		if (!root_module) {
			return "||messages||"+message_dump.str();
		}
		else { 
			root_module->handleDependencies();

			top_ctx.setDocumentPath(parentpath.c_str());
			AbstractNode::resetIndexCounter();
			absolute_root_node = root_module->instantiate(&top_ctx, &root_inst, NULL);

			// Do we have an explicit root node (! modifier)?
			if (!(root_node = find_root_tag(absolute_root_node))) root_node = absolute_root_node;

			tree.setRoot(root_node);
			
			root_geom = geomevaluator.evaluateGeometry(*tree.root(), true);
			if (!root_geom) root_geom.reset(new CGAL_Nef_polyhedron());
			
			std::stringstream output;
			export_mesh( root_geom.get() , output ); 		
			
			delete root_node;

			return output.str()+"||messages||"+message_dump.str();
		}
	  } 
	   catch (std::exception& e)
	  {
		return std::string("Error In Yr OpenScad\r\n");
	  }
}

class session
{
public:
  
  session(boost::asio::io_service& io_service) : socket_(io_service) { }

  tcp::socket& socket() { return socket_; }

  void start() {
	boost::asio::async_read_until(socket_, response_, "//done//", boost::bind(&session::handle_read, this, boost::asio::placeholders::error));
  }

  void handle_read(const boost::system::error_code& err) {
    if (!err)
    {		
		std::string script_buffer((std::istreambuf_iterator<char>(&response_)), std::istreambuf_iterator<char>());
		std::string stl = process_request(script_buffer) + "//done//\r\n";
		message_dump.str("");
		boost::asio::async_write(socket_, boost::asio::buffer(stl, stl.length()), boost::bind(&session::handle_write, this, boost::asio::placeholders::error));	
	}
    else
    {
      delete this;
    }
  }

  void handle_write(const boost::system::error_code& error )
  {
    if (!error)
    {
		std::cout << "the end" << std::endl; 
		//delete this; 
	}
    else
    {
      delete this;
    }
  }

private:
  std::string script_buffer; 
  tcp::socket socket_;
  enum { max_length = 1024 };
  boost::asio::streambuf response_;
};

class server
{
public:
  server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
  {
    session* new_session = new session(io_service_);
    acceptor_.async_accept(new_session->socket(),
        boost::bind(&server::handle_accept, this, new_session,
          boost::asio::placeholders::error));
  }

  void handle_accept(session* new_session,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      new_session->start();
      new_session = new session(io_service_);
      acceptor_.async_accept(new_session->socket(),
          boost::bind(&server::handle_accept, this, new_session,
            boost::asio::placeholders::error));
    }
    else
    {
      delete new_session;
    }
  }

private:
  boost::asio::io_service& io_service_;
  tcp::acceptor acceptor_;
};


int main(int argc, char* argv[])
{
  	
	StackCheck::inst()->init();
	PlatformUtils::ensureStdIO();
	CGAL::set_error_behaviour(CGAL::ABORT);
	Builtins::instance()->initialize();
	CURRENTDIR = std::string("/home/mixotricha/workspace/newscad/");

	std::cout << "Starting Openscad Server on port: " << argv[1] << std::endl; 
	std::cout << "Working directory is: " << argv[0] << std::endl; 

	NodeCache nodecache;
	NodeDumper dumper(nodecache);

	try
	  {
		if (argc != 2)
		{
		  std::cerr << "Usage: async_tcp_echo_server <port>\n";
		  return 1;
		}

		boost::asio::io_service io_service;

		using namespace std; // For atoi.
		server s(io_service, atoi(argv[1]));

		io_service.run();
	  }
	  catch (std::exception& e)
	  {
		std::cerr << "Exception: " << e.what() << "\n";
	  }

	  

	return 0;
}
