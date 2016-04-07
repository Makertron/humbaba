#############################################################################
# Makefile for building: openscad makertron server 
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DOPENSCAD_VERSION=2015.03-2 -DOPENSCAD_SHORTVERSION=2015.03 -DOPENSCAD_YEAR=2015.0 -DOPENSCAD_MONTH=03.0 -DOPENSCAD_DAY=.0 -DDEBUG -DENABLE_CGAL -DENABLE_OPENCSG
CFLAGS        = -g -m64 -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -g -m64 -pipe -fno-strict-aliasing -frounding-math -DEIGEN_DONT_ALIGN -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/freetype2 -O2 -D_REENTRANT -Wall -W -Wno-unused-local-typedefs $(DEFINES)
INCPATH       = -I. -I/usr/include/eigen3 -Isrc -Isrc/libtess2/Include -Iobjects
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lCGAL -lmpfr -lgmp -lopencsg -lGLEW -lboost_thread -lboost_program_options -lboost_filesystem -lboost_system -lboost_regex -lglib-2.0 -lharfbuzz -lfontconfig -lfreetype -L/usr/lib/x86_64-linux-gnu -lGL -lGLU -lX11 -lpthread 
AR            = ar cqs
RANLIB        = 
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p


####### Output directory

OBJECTS_DIR   = objects/

####### Files

SOURCES       = src/version_check.cc \
		src/mathc99.cc \
		src/linalg.cc \
		src/Camera.cc \
		src/handle_dep.cc \
		src/value.cc \
		src/expr.cc \
		src/stackcheck.cc \
		src/func.cc \
		src/localscope.cc \
		src/module.cc \
		src/feature.cc \
		src/node.cc \
		src/context.cc \
		src/modcontext.cc \
		src/evalcontext.cc \
		src/csgterm.cc \
		src/csgtermnormalizer.cc \
		src/Geometry.cc \
		src/Polygon2d.cc \
		src/clipper-utils.cc \
		src/polyset-utils.cc \
		src/GeometryUtils.cc \
		src/polyset.cc \
		src/csgops.cc \
		src/transform.cc \
		src/color.cc \
		src/primitives.cc \
		src/projection.cc \
		src/cgaladv.cc \
		src/surface.cc \
		src/control.cc \
		src/render.cc \
		src/text.cc \
		src/dxfdata.cc \
		src/dxfdim.cc \
		src/offset.cc \
		src/linearextrude.cc \
		src/rotateextrude.cc \
		src/printutils.cc \
		src/fileutils.cc \
		src/progress.cc \
		src/parsersettings.cc \
		src/stl-utils.cc \
		src/boost-utils.cc \
		src/PlatformUtils.cc \
		src/nodedumper.cc \
		src/traverser.cc \
		src/GeometryEvaluator.cc \
		src/ModuleCache.cc \
		src/GeometryCache.cc \
		src/Tree.cc \
		src/DrawingCallback.cc \
		src/FreetypeRenderer.cc \
		src/FontCache.cc \
		src/settings.cc \
		src/rendersettings.cc \
		src/GLView.cc \
		src/grid.cc \
		src/builtin.cc \
		src/calc.cc \
		src/export.cc \
		src/export_png.cc \
		src/import.cc \
		src/renderer.cc \
		src/colormap.cc \
		src/ThrownTogetherRenderer.cc \
		src/CSGTermEvaluator.cc \
		src/svg.cc \
		src/OffscreenView.cc \
		src/fbo.cc \
		src/system-gl.cc \
		src/imageutils.cc \
		src/lodepng.cpp \
		src/openscad.cc \
		src/polyclipping/clipper.cpp \
		src/libtess2/Source/bucketalloc.c \
		src/libtess2/Source/dict.c \
		src/libtess2/Source/geom.c \
		src/libtess2/Source/mesh.c \
		src/libtess2/Source/priorityq.c \
		src/libtess2/Source/sweep.c \
		src/libtess2/Source/tess.c \
		src/imageutils-lodepng.cc \
		src/OffscreenContextGLX.cc \
		src/OpenCSGRenderer.cc \
		src/cgalutils.cc \
		src/cgalutils-tess.cc \
		src/cgalutils-polyhedron.cc \
		src/CGALCache.cc \
		src/CGALRenderer.cc \
		src/CGAL_Nef_polyhedron.cc \
		src/Polygon2d-CGAL.cc \
		src/PlatformUtils-posix.cc \
		parser_yacc.cpp \
		lexer_lex.cpp
OBJECTS  = objects/version_check.o \
		objects/mathc99.o \
		objects/linalg.o \
		objects/Camera.o \
		objects/handle_dep.o \
		objects/value.o \
		objects/expr.o \
		objects/stackcheck.o \
		objects/func.o \
		objects/localscope.o \
		objects/module.o \
		objects/feature.o \
		objects/node.o \
		objects/context.o \
		objects/modcontext.o \
		objects/evalcontext.o \
		objects/csgterm.o \
		objects/csgtermnormalizer.o \
		objects/Geometry.o \
		objects/Polygon2d.o \
		objects/clipper-utils.o \
		objects/polyset-utils.o \
		objects/GeometryUtils.o \
		objects/polyset.o \
		objects/csgops.o \
		objects/transform.o \
		objects/color.o \
		objects/primitives.o \
		objects/projection.o \
		objects/cgaladv.o \
		objects/surface.o \
		objects/control.o \
		objects/render.o \
		objects/text.o \
		objects/dxfdata.o \
		objects/dxfdim.o \
		objects/offset.o \
		objects/linearextrude.o \
		objects/rotateextrude.o \
		objects/printutils.o \
		objects/fileutils.o \
		objects/progress.o \
		objects/parsersettings.o \
		objects/stl-utils.o \
		objects/boost-utils.o \
		objects/PlatformUtils.o \
		objects/nodedumper.o \
		objects/traverser.o \
		objects/GeometryEvaluator.o \
		objects/ModuleCache.o \
		objects/GeometryCache.o \
		objects/Tree.o \
		objects/DrawingCallback.o \
		objects/FreetypeRenderer.o \
		objects/FontCache.o \
		objects/settings.o \
		objects/rendersettings.o \
		objects/GLView.o \
		objects/grid.o \
		objects/builtin.o \
		objects/calc.o \
		objects/export.o \
		objects/export_png.o \
		objects/import.o \
		objects/renderer.o \
		objects/colormap.o \
		objects/ThrownTogetherRenderer.o \
		objects/CSGTermEvaluator.o \
		objects/svg.o \
		objects/OffscreenView.o \
		objects/fbo.o \
		objects/system-gl.o \
		objects/imageutils.o \
		objects/lodepng.o \
		objects/openscad.o \
		objects/clipper.o \
		objects/bucketalloc.o \
		objects/dict.o \
		objects/geom.o \
		objects/mesh.o \
		objects/priorityq.o \
		objects/sweep.o \
		objects/tess.o \
		objects/imageutils-lodepng.o \
		objects/OffscreenContextGLX.o \
		objects/OpenCSGRenderer.o \
		objects/cgalutils.o \
		objects/cgalutils-tess.o \
		objects/cgalutils-polyhedron.o \
		objects/CGALCache.o \
		objects/CGALRenderer.o \
		objects/CGAL_Nef_polyhedron.o \
		objects/Polygon2d-CGAL.o \
		objects/PlatformUtils-posix.o \
		objects/parser_yacc.o \
		objects/lexer_lex.o
DIST  = version.pri \
		win.pri \
		flex.pri \
		bison.pri \
		cgal.pri \
		opencsg.pri \
		glew.pri \
		eigen.pri \
		boost.pri \
		glib-2.0.pri \
		gettext.pri \
		sparkle.pri \
		harfbuzz.pri \
		freetype.pri \
		fontconfig.pri \
		common.pri \
		openscad.pro
QMAKE_TARGET  = openscad
DESTDIR       = 
TARGET        = openscad

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_flex_make_all:
compiler_flex_clean:
compiler_bison_make_all:
compiler_bison_clean:
compiler_bison_header_make_all:
compiler_bison_header_clean:

compiler_yacc_decl_make_all: parser_yacc.h
compiler_yacc_decl_clean:
	-$(DEL_FILE) parser_yacc.h
parser_yacc.h: src/parser.y
	/usr/bin/bison -d -p parser -b parser src/parser.y
	 rm -f parser_yacc.h parser_yacc.cpp
	 mv -f parser.tab.h parser_yacc.h
	 mv -f parser.tab.c parser_yacc.cpp
	

compiler_yacc_impl_make_all: parser_yacc.cpp
compiler_yacc_impl_clean:
	-$(DEL_FILE) parser_yacc.cpp
parser_yacc.cpp: src/parser.y \
		parser_yacc.h
	


compiler_lex_make_all: lexer_lex.cpp
compiler_lex_clean:
	-$(DEL_FILE) lexer_lex.cpp
lexer_lex.cpp: src/lexer.l
	/usr/bin/flex -Plexer src/lexer.l
	 rm -f lexer_lex.cpp
	 mv -f lex.lexer.c lexer_lex.cpp
	

compiler_clean: compiler_yacc_decl_clean compiler_yacc_impl_clean compiler_lex_clean 

####### Compile

objects/version_check.o: src/version_check.cc src/version_check.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/version_check.o src/version_check.cc

objects/mathc99.o: src/mathc99.cc src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/mathc99.o src/mathc99.cc

objects/linalg.o: src/linalg.cc src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/linalg.o src/linalg.cc

objects/Camera.o: src/Camera.cc src/Camera.h \
		src/linalg.h \
		src/rendersettings.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/Camera.o src/Camera.cc

objects/handle_dep.o: src/handle_dep.cc src/handle_dep.h \
		src/boosty.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/handle_dep.o src/handle_dep.cc

objects/value.o: src/value.cc src/value.h \
		src/memory.h \
		src/printutils.h \
		src/boost-utils.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/value.o src/value.cc

objects/expr.o: src/expr.cc src/expression.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/evalcontext.h \
		src/context.h \
		src/stl-utils.h \
		src/printutils.h \
		src/stackcheck.h \
		src/exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/expr.o src/expr.cc

objects/stackcheck.o: src/stackcheck.cc src/stackcheck.h \
		src/PlatformUtils.h \
		src/boosty.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/stackcheck.o src/stackcheck.cc

objects/func.o: src/func.cc src/function.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/feature.h \
		src/expression.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/module.h \
		src/localscope.h \
		src/mathc99.h \
		src/stl-utils.h \
		src/printutils.h \
		src/stackcheck.h \
		src/exceptions.h \
		src/boost-utils.h \
		src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/func.o src/func.cc

objects/localscope.o: src/localscope.cc src/localscope.h \
		src/typedefs.h \
		src/modcontext.h \
		src/context.h \
		src/value.h \
		src/memory.h \
		src/module.h \
		src/feature.h \
		src/expression.h \
		src/function.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/localscope.o src/localscope.cc

objects/module.o: src/module.cc src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/ModuleCache.h \
		src/node.h \
		src/traverser.h \
		src/modcontext.h \
		src/context.h \
		src/evalcontext.h \
		src/expression.h \
		src/function.h \
		src/printutils.h \
		src/parsersettings.h \
		src/exceptions.h \
		src/stackcheck.h \
		src/boosty.h \
		src/FontCache.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/module.o src/module.cc

objects/feature.o: src/feature.cc src/feature.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/feature.o src/feature.cc

objects/node.o: src/node.cc src/node.h \
		src/traverser.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/progress.h \
		src/visitor.h \
		src/stl-utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/node.o src/node.cc

objects/context.o: src/context.cc src/context.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/evalcontext.h \
		src/expression.h \
		src/function.h \
		src/feature.h \
		src/module.h \
		src/localscope.h \
		src/builtin.h \
		src/printutils.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/context.o src/context.cc

objects/modcontext.o: src/modcontext.cc src/modcontext.h \
		src/context.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/module.h \
		src/localscope.h \
		src/feature.h \
		src/expression.h \
		src/function.h \
		src/printutils.h \
		src/builtin.h \
		src/ModuleCache.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/modcontext.o src/modcontext.cc

objects/evalcontext.o: src/evalcontext.cc src/evalcontext.h \
		src/context.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/module.h \
		src/localscope.h \
		src/feature.h \
		src/expression.h \
		src/function.h \
		src/printutils.h \
		src/builtin.h \
		src/exceptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/evalcontext.o src/evalcontext.cc

objects/csgterm.o: src/csgterm.cc src/csgterm.h \
		src/memory.h \
		src/linalg.h \
		src/Geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/csgterm.o src/csgterm.cc

objects/csgtermnormalizer.o: src/csgtermnormalizer.cc src/csgtermnormalizer.h \
		src/memory.h \
		src/csgterm.h \
		src/linalg.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/csgtermnormalizer.o src/csgtermnormalizer.cc

objects/Geometry.o: src/Geometry.cc src/Geometry.h \
		src/linalg.h \
		src/memory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/Geometry.o src/Geometry.cc

objects/Polygon2d.o: src/Polygon2d.cc src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/Polygon2d.o src/Polygon2d.cc

objects/clipper-utils.o: src/clipper-utils.cc src/clipper-utils.h \
		src/polyclipping/clipper.hpp \
		src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/clipper-utils.o src/clipper-utils.cc

objects/polyset-utils.o: src/polyset-utils.cc src/polyset-utils.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/printutils.h \
		src/Reindexer.h \
		src/grid.h \
		src/mathc99.h \
		src/cgalutils.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/polyset-utils.o src/polyset-utils.cc

objects/GeometryUtils.o: src/GeometryUtils.cc src/GeometryUtils.h \
		src/linalg.h \
		src/printutils.h \
		src/Reindexer.h \
		src/grid.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/GeometryUtils.o src/GeometryUtils.cc

objects/polyset.o: src/polyset.cc src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/polyset-utils.h \
		src/printutils.h \
		src/grid.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/polyset.o src/polyset.cc

objects/csgops.o: src/csgops.cc src/csgnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/enums.h \
		src/evalcontext.h \
		src/context.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/module.h \
		src/localscope.h \
		src/feature.h \
		src/csgterm.h \
		src/linalg.h \
		src/builtin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/csgops.o src/csgops.cc

objects/transform.o: src/transform.cc src/transformnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/linalg.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/polyset.h \
		src/Geometry.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/builtin.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/transform.o src/transform.cc

objects/color.o: src/color.cc src/colornode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/linalg.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/color.o src/color.cc

objects/primitives.o: src/primitives.cc src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/node.h \
		src/traverser.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/printutils.h \
		src/visitor.h \
		src/calc.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/primitives.o src/primitives.cc

objects/projection.o: src/projection.cc src/projectionnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/printutils.h \
		src/builtin.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/projection.o src/projection.cc

objects/cgaladv.o: src/cgaladv.cc src/cgaladvnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/value.h \
		src/memory.h \
		src/linalg.h \
		src/module.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/polyset.h \
		src/Geometry.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/cgaladv.o src/cgaladv.cc

objects/surface.o: src/surface.cc src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/node.h \
		src/traverser.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/printutils.h \
		src/fileutils.h \
		src/handle_dep.h \
		src/visitor.h \
		src/lodepng.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/surface.o src/surface.cc

objects/control.o: src/control.cc src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/node.h \
		src/traverser.h \
		src/evalcontext.h \
		src/context.h \
		src/modcontext.h \
		src/expression.h \
		src/builtin.h \
		src/printutils.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/control.o src/control.cc

objects/render.o: src/render.cc src/rendernode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/render.o src/render.cc

objects/text.o: src/text.cc src/calc.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/printutils.h \
		src/builtin.h \
		src/textnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/FreetypeRenderer.h \
		src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/text.o src/text.cc

objects/dxfdata.o: src/dxfdata.cc src/dxfdata.h \
		src/linalg.h \
		src/grid.h \
		src/mathc99.h \
		src/printutils.h \
		src/handle_dep.h \
		src/calc.h \
		src/value.h \
		src/memory.h \
		src/boost-utils.h \
		src/boosty.h \
		src/Polygon2d.h \
		src/Geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/dxfdata.o src/dxfdata.cc

objects/dxfdim.o: src/dxfdim.cc src/dxfdim.h \
		src/value.h \
		src/memory.h \
		src/function.h \
		src/typedefs.h \
		src/feature.h \
		src/dxfdata.h \
		src/linalg.h \
		src/builtin.h \
		src/module.h \
		src/localscope.h \
		src/printutils.h \
		src/fileutils.h \
		src/evalcontext.h \
		src/context.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/dxfdim.o src/dxfdim.cc

objects/offset.o: src/offset.cc src/offsetnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/value.h \
		src/memory.h \
		src/clipper-utils.h \
		src/polyclipping/clipper.hpp \
		src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/module.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/printutils.h \
		src/fileutils.h \
		src/builtin.h \
		src/calc.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/offset.o src/offset.cc

objects/linearextrude.o: src/linearextrude.cc src/linearextrudenode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/value.h \
		src/memory.h \
		src/module.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/printutils.h \
		src/fileutils.h \
		src/builtin.h \
		src/calc.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/linearextrude.o src/linearextrude.cc

objects/rotateextrude.o: src/rotateextrude.cc src/rotateextrudenode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/value.h \
		src/memory.h \
		src/module.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/evalcontext.h \
		src/context.h \
		src/printutils.h \
		src/fileutils.h \
		src/builtin.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/rotateextrude.o src/rotateextrude.cc

objects/printutils.o: src/printutils.cc src/printutils.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/printutils.o src/printutils.cc

objects/fileutils.o: src/fileutils.cc src/fileutils.h \
		src/printutils.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/fileutils.o src/fileutils.cc

objects/progress.o: src/progress.cc src/progress.h \
		src/node.h \
		src/traverser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/progress.o src/progress.cc

objects/parsersettings.o: src/parsersettings.cc src/parsersettings.h \
		src/boosty.h \
		src/printutils.h \
		src/PlatformUtils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/parsersettings.o src/parsersettings.cc

objects/stl-utils.o: src/stl-utils.cc 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/stl-utils.o src/stl-utils.cc

objects/boost-utils.o: src/boost-utils.cc src/boosty.h \
		src/printutils.h \
		src/boost-utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/boost-utils.o src/boost-utils.cc

objects/PlatformUtils.o: src/PlatformUtils.cc src/PlatformUtils.h \
		src/boosty.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/PlatformUtils.o src/PlatformUtils.cc

objects/nodedumper.o: src/nodedumper.cc src/nodedumper.h \
		src/visitor.h \
		src/traverser.h \
		src/nodecache.h \
		src/node.h \
		src/state.h \
		src/linalg.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/nodedumper.o src/nodedumper.cc

objects/traverser.o: src/traverser.cc src/traverser.h \
		src/visitor.h \
		src/node.h \
		src/state.h \
		src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/traverser.o src/traverser.cc

objects/GeometryEvaluator.o: src/GeometryEvaluator.cc src/GeometryEvaluator.h \
		src/visitor.h \
		src/traverser.h \
		src/enums.h \
		src/memory.h \
		src/Geometry.h \
		src/linalg.h \
		src/Tree.h \
		src/nodecache.h \
		src/node.h \
		src/GeometryCache.h \
		src/cache.h \
		src/printutils.h \
		src/CGALCache.h \
		src/Polygon2d.h \
		src/module.h \
		src/value.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/state.h \
		src/offsetnode.h \
		src/clipper-utils.h \
		src/polyclipping/clipper.hpp \
		src/transformnode.h \
		src/linearextrudenode.h \
		src/rotateextrudenode.h \
		src/csgnode.h \
		src/cgaladvnode.h \
		src/projectionnode.h \
		src/textnode.h \
		src/FreetypeRenderer.h \
		src/CGAL_Nef_polyhedron.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/cgalutils.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/rendernode.h \
		src/polyset-utils.h \
		src/calc.h \
		src/svg.h \
		src/dxfdata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/GeometryEvaluator.o src/GeometryEvaluator.cc

objects/ModuleCache.o: src/ModuleCache.cc src/ModuleCache.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/printutils.h \
		src/openscad.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/ModuleCache.o src/ModuleCache.cc

objects/GeometryCache.o: src/GeometryCache.cc src/GeometryCache.h \
		src/cache.h \
		src/printutils.h \
		src/memory.h \
		src/Geometry.h \
		src/linalg.h \
		src/CGAL_Nef_polyhedron.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/GeometryCache.o src/GeometryCache.cc

objects/Tree.o: src/Tree.cc src/Tree.h \
		src/nodecache.h \
		src/node.h \
		src/traverser.h \
		src/nodedumper.h \
		src/visitor.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/Tree.o src/Tree.cc

objects/DrawingCallback.o: src/DrawingCallback.cc src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/DrawingCallback.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/DrawingCallback.o src/DrawingCallback.cc

objects/FreetypeRenderer.o: src/FreetypeRenderer.cc src/printutils.h \
		src/FontCache.h \
		src/DrawingCallback.h \
		src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/FreetypeRenderer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/FreetypeRenderer.o src/FreetypeRenderer.cc

objects/FontCache.o: src/FontCache.cc src/boosty.h \
		src/printutils.h \
		src/FontCache.h \
		src/PlatformUtils.h \
		src/parsersettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/FontCache.o src/FontCache.cc

objects/settings.o: src/settings.cc src/settings.h \
		src/value.h \
		src/memory.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/settings.o src/settings.cc

objects/rendersettings.o: src/rendersettings.cc src/rendersettings.h \
		src/linalg.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/rendersettings.o src/rendersettings.cc

objects/GLView.o: src/GLView.cc src/GLView.h \
		src/system-gl.h \
		src/Camera.h \
		src/linalg.h \
		src/colormap.h \
		src/rendersettings.h \
		src/mathc99.h \
		src/printutils.h \
		src/renderer.h \
		src/memory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/GLView.o src/GLView.cc

objects/grid.o: src/grid.cc src/grid.h \
		src/mathc99.h \
		src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/grid.o src/grid.cc

objects/builtin.o: src/builtin.cc src/builtin.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/function.h \
		src/expression.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/builtin.o src/builtin.cc

objects/calc.o: src/calc.cc src/calc.h \
		src/grid.h \
		src/mathc99.h \
		src/linalg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/calc.o src/calc.cc

objects/export.o: src/export.cc src/export.h \
		src/Tree.h \
		src/nodecache.h \
		src/node.h \
		src/traverser.h \
		src/Camera.h \
		src/linalg.h \
		src/memory.h \
		src/printutils.h \
		src/polyset.h \
		src/Geometry.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/polyset-utils.h \
		src/dxfdata.h \
		src/CGAL_Nef_polyhedron.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/cgalutils.h \
		src/enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/export.o src/export.cc

objects/export_png.o: src/export_png.cc src/export.h \
		src/Tree.h \
		src/nodecache.h \
		src/node.h \
		src/traverser.h \
		src/Camera.h \
		src/linalg.h \
		src/memory.h \
		src/printutils.h \
		src/OffscreenView.h \
		src/OffscreenContext.h \
		src/fbo.h \
		src/system-gl.h \
		src/GLView.h \
		src/colormap.h \
		src/CsgInfo.h \
		src/csgterm.h \
		src/GeometryEvaluator.h \
		src/visitor.h \
		src/enums.h \
		src/Geometry.h \
		src/CSGTermEvaluator.h \
		src/csgtermnormalizer.h \
		src/rendersettings.h \
		src/polyset.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/Polygon2d.h \
		src/CGALRenderer.h \
		src/CGAL_Nef_polyhedron.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/cgalutils.h \
		src/OpenCSGRenderer.h \
		src/ThrownTogetherRenderer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/export_png.o src/export_png.cc

objects/import.o: src/import.cc src/importnode.h \
		src/node.h \
		src/traverser.h \
		src/visitor.h \
		src/value.h \
		src/memory.h \
		src/module.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/evalcontext.h \
		src/context.h \
		src/builtin.h \
		src/dxfdata.h \
		src/printutils.h \
		src/fileutils.h \
		src/handle_dep.h \
		src/cgalutils.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h \
		src/boosty.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/import.o src/import.cc

objects/renderer.o: src/renderer.cc src/renderer.h \
		src/system-gl.h \
		src/linalg.h \
		src/memory.h \
		src/colormap.h \
		src/rendersettings.h \
		src/Geometry.h \
		src/polyset.h \
		src/GeometryUtils.h \
		src/Polygon2d.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/renderer.o src/renderer.cc

objects/colormap.o: src/colormap.cc src/colormap.h \
		src/linalg.h \
		src/boosty.h \
		src/printutils.h \
		src/PlatformUtils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/colormap.o src/colormap.cc

objects/ThrownTogetherRenderer.o: src/ThrownTogetherRenderer.cc src/ThrownTogetherRenderer.h \
		src/renderer.h \
		src/system-gl.h \
		src/linalg.h \
		src/memory.h \
		src/colormap.h \
		src/polyset.h \
		src/Geometry.h \
		src/GeometryUtils.h \
		src/Polygon2d.h \
		src/csgterm.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/ThrownTogetherRenderer.o src/ThrownTogetherRenderer.cc

objects/CSGTermEvaluator.o: src/CSGTermEvaluator.cc src/CSGTermEvaluator.h \
		src/visitor.h \
		src/traverser.h \
		src/memory.h \
		src/state.h \
		src/linalg.h \
		src/csgterm.h \
		src/module.h \
		src/value.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/csgnode.h \
		src/node.h \
		src/enums.h \
		src/transformnode.h \
		src/colornode.h \
		src/rendernode.h \
		src/cgaladvnode.h \
		src/printutils.h \
		src/GeometryEvaluator.h \
		src/Geometry.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/polyset-utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/CSGTermEvaluator.o src/CSGTermEvaluator.cc

objects/svg.o: src/svg.cc src/svg.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/cgalutils.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/svg.o src/svg.cc

objects/OffscreenView.o: src/OffscreenView.cc src/OffscreenView.h \
		src/OffscreenContext.h \
		src/fbo.h \
		src/system-gl.h \
		src/GLView.h \
		src/Camera.h \
		src/linalg.h \
		src/colormap.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/OffscreenView.o src/OffscreenView.cc

objects/fbo.o: src/fbo.cc src/fbo.h \
		src/system-gl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/fbo.o src/fbo.cc

objects/system-gl.o: src/system-gl.cc src/system-gl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/system-gl.o src/system-gl.cc

objects/imageutils.o: src/imageutils.cc src/imageutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/imageutils.o src/imageutils.cc

objects/lodepng.o: src/lodepng.cpp src/lodepng.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/lodepng.o src/lodepng.cpp

objects/openscad.o: src/openscad.cc src/openscad.h \
		src/node.h \
		src/traverser.h \
		src/module.h \
		src/value.h \
		src/memory.h \
		src/typedefs.h \
		src/localscope.h \
		src/feature.h \
		src/modcontext.h \
		src/context.h \
		src/export.h \
		src/Tree.h \
		src/nodecache.h \
		src/Camera.h \
		src/linalg.h \
		src/builtin.h \
		src/printutils.h \
		src/handle_dep.h \
		src/parsersettings.h \
		src/rendersettings.h \
		src/PlatformUtils.h \
		src/boosty.h \
		src/nodedumper.h \
		src/visitor.h \
		src/stackcheck.h \
		src/CocoaUtils.h \
		src/FontCache.h \
		src/CGAL_Nef_polyhedron.h \
		src/Geometry.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/cgalutils.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/enums.h \
		src/csgterm.h \
		src/CSGTermEvaluator.h \
		src/CsgInfo.h \
		src/OffscreenView.h \
		src/OffscreenContext.h \
		src/fbo.h \
		src/GLView.h \
		src/GeometryEvaluator.h \
		src/csgtermnormalizer.h \
		src/AppleEvents.h \
		src/SparkleAutoUpdater.h \
		src/EventFilter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/openscad.o src/openscad.cc

objects/clipper.o: src/polyclipping/clipper.cpp src/polyclipping/clipper.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/clipper.o src/polyclipping/clipper.cpp

objects/bucketalloc.o: src/libtess2/Source/bucketalloc.c src/libtess2/Include/tesselator.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/bucketalloc.o src/libtess2/Source/bucketalloc.c

objects/dict.o: src/libtess2/Source/dict.c src/libtess2/Include/tesselator.h \
		src/libtess2/Source/bucketalloc.h \
		src/libtess2/Source/dict.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/dict.o src/libtess2/Source/dict.c

objects/geom.o: src/libtess2/Source/geom.c src/libtess2/Source/mesh.h \
		src/libtess2/Include/tesselator.h \
		src/libtess2/Source/geom.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/geom.o src/libtess2/Source/geom.c

objects/mesh.o: src/libtess2/Source/mesh.c src/libtess2/Source/mesh.h \
		src/libtess2/Include/tesselator.h \
		src/libtess2/Source/geom.h \
		src/libtess2/Source/bucketalloc.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/mesh.o src/libtess2/Source/mesh.c

objects/priorityq.o: src/libtess2/Source/priorityq.c src/libtess2/Include/tesselator.h \
		src/libtess2/Source/priorityq.h \
		src/libtess2/Source/geom.h \
		src/libtess2/Source/mesh.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/priorityq.o src/libtess2/Source/priorityq.c

objects/sweep.o: src/libtess2/Source/sweep.c src/libtess2/Source/mesh.h \
		src/libtess2/Include/tesselator.h \
		src/libtess2/Source/geom.h \
		src/libtess2/Source/tess.h \
		src/libtess2/Source/bucketalloc.h \
		src/libtess2/Source/dict.h \
		src/libtess2/Source/priorityq.h \
		src/libtess2/Source/sweep.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/sweep.o src/libtess2/Source/sweep.c

objects/tess.o: src/libtess2/Source/tess.c src/libtess2/Source/bucketalloc.h \
		src/libtess2/Source/tess.h \
		src/libtess2/Source/mesh.h \
		src/libtess2/Include/tesselator.h \
		src/libtess2/Source/dict.h \
		src/libtess2/Source/priorityq.h \
		src/libtess2/Source/sweep.h \
		src/libtess2/Source/geom.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o objects/tess.o src/libtess2/Source/tess.c

objects/imageutils-lodepng.o: src/imageutils-lodepng.cc src/imageutils.h \
		src/lodepng.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/imageutils-lodepng.o src/imageutils-lodepng.cc

objects/OffscreenContextGLX.o: src/OffscreenContextGLX.cc src/OffscreenContext.h \
		src/fbo.h \
		src/system-gl.h \
		src/printutils.h \
		src/imageutils.h \
		src/OffscreenContextAll.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/OffscreenContextGLX.o src/OffscreenContextGLX.cc

objects/OpenCSGRenderer.o: src/OpenCSGRenderer.cc src/system-gl.h \
		src/OpenCSGRenderer.h \
		src/renderer.h \
		src/linalg.h \
		src/memory.h \
		src/colormap.h \
		src/polyset.h \
		src/Geometry.h \
		src/GeometryUtils.h \
		src/Polygon2d.h \
		src/csgterm.h \
		src/stl-utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/OpenCSGRenderer.o src/OpenCSGRenderer.cc

objects/cgalutils.o: src/cgalutils.cc src/cgalutils.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h \
		src/polyset-utils.h \
		src/grid.h \
		src/mathc99.h \
		src/node.h \
		src/traverser.h \
		src/convex_hull_3_bugfix.h \
		src/svg.h \
		src/Reindexer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/cgalutils.o src/cgalutils.cc

objects/cgalutils-tess.o: src/cgalutils-tess.cc src/cgalutils.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/cgalutils-tess.o src/cgalutils-tess.cc

objects/cgalutils-polyhedron.o: src/cgalutils-polyhedron.cc src/cgalutils.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/polyset.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/CGAL_Nef_polyhedron.h \
		src/enums.h \
		src/polyset-utils.h \
		src/grid.h \
		src/mathc99.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/cgalutils-polyhedron.o src/cgalutils-polyhedron.cc

objects/CGALCache.o: src/CGALCache.cc src/CGALCache.h \
		src/cache.h \
		src/printutils.h \
		src/memory.h \
		src/CGAL_Nef_polyhedron.h \
		src/Geometry.h \
		src/linalg.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/CGALCache.o src/CGALCache.cc

objects/CGALRenderer.o: src/CGALRenderer.cc src/dxfdata.h \
		src/linalg.h \
		src/polyset.h \
		src/Geometry.h \
		src/memory.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/polyset-utils.h \
		src/printutils.h \
		src/CGALRenderer.h \
		src/CGAL_Nef_polyhedron.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/CGAL_OGL_Polyhedron.h \
		src/rendersettings.h \
		src/OGL_helper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/CGALRenderer.o src/CGALRenderer.cc

objects/CGAL_Nef_polyhedron.o: src/CGAL_Nef_polyhedron.cc src/CGAL_Nef_polyhedron.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/cgalutils.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h \
		src/Polygon2d.h \
		src/enums.h \
		src/svg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/CGAL_Nef_polyhedron.o src/CGAL_Nef_polyhedron.cc

objects/Polygon2d-CGAL.o: src/Polygon2d-CGAL.cc src/Polygon2d-CGAL.h \
		src/Polygon2d.h \
		src/Geometry.h \
		src/linalg.h \
		src/memory.h \
		src/cgal.h \
		src/CGAL_workaround_Mark_bounded_volumes.h \
		src/CGAL_Nef3_workaround.h \
		src/printutils.h \
		src/CGAL_Nef_polyhedron.h \
		src/polyset.h \
		src/system-gl.h \
		src/GeometryUtils.h \
		src/renderer.h \
		src/colormap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/Polygon2d-CGAL.o src/Polygon2d-CGAL.cc

objects/PlatformUtils-posix.o: src/PlatformUtils-posix.cc src/PlatformUtils.h \
		src/boosty.h \
		src/printutils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/PlatformUtils-posix.o src/PlatformUtils-posix.cc

objects/parser_yacc.o: parser_yacc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/parser_yacc.o parser_yacc.cpp

objects/lexer_lex.o: lexer_lex.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/lexer_lex.o lexer_lex.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/bin/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/usr/local/bin/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/usr/local/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/bin/ 


install_translation_fr: first locale/fr.po FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/locale/fr/LC_MESSAGES/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/locale/fr/LC_MESSAGES/ 
	cp -f locale/fr/LC_MESSAGES/openscad.mo "$(INSTALL_ROOT)/usr/local/share/openscad/locale/fr/LC_MESSAGES/openscad.mo"


install_translation_ru: first locale/ru.po FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/locale/ru/LC_MESSAGES/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/locale/ru/LC_MESSAGES/ 
	cp -f locale/ru/LC_MESSAGES/openscad.mo "$(INSTALL_ROOT)/usr/local/share/openscad/locale/ru/LC_MESSAGES/openscad.mo"


install_translation_de: first locale/de.po FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/locale/de/LC_MESSAGES/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/locale/de/LC_MESSAGES/ 
	cp -f locale/de/LC_MESSAGES/openscad.mo "$(INSTALL_ROOT)/usr/local/share/openscad/locale/de/LC_MESSAGES/openscad.mo"


install_translation_cs: first locale/cs.po FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/locale/cs/LC_MESSAGES/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/locale/cs/LC_MESSAGES/ 
	cp -f locale/cs/LC_MESSAGES/openscad.mo "$(INSTALL_ROOT)/usr/local/share/openscad/locale/cs/LC_MESSAGES/openscad.mo"

install_translation_es: first locale/es.po FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/locale/es/LC_MESSAGES/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/locale/es/LC_MESSAGES/ 
	cp -f locale/es/LC_MESSAGES/openscad.mo "$(INSTALL_ROOT)/usr/local/share/openscad/locale/es/LC_MESSAGES/openscad.mo"

install_libraries: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/openscad/libraries/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/openscad/libraries/ 
	-$(INSTALL_DIR) /home/ubuntu/openscad-2015.03-2/libraries/MCAD $(INSTALL_ROOT)/usr/local/share/openscad/libraries/

uninstall_libraries:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/share/openscad/libraries/MCAD
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/share/openscad/libraries/ 

install_applications: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/applications/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/applications/ 
	cat icons/openscad.desktop | sed -e "s/^Icon=openscad/Icon=openscad/; s/^Exec=openscad/Exec=openscad/" > "$(INSTALL_ROOT)/usr/local/share/applications/openscad.desktop"

install_mimexml: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/mime/packages/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/mime/packages/ 
	cp -f icons/openscad.xml "$(INSTALL_ROOT)/usr/local/share/mime/packages/openscad.xml"


install_appdata: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/share/appdata/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/share/appdata/ 
	cp -f openscad.appdata.xml "$(INSTALL_ROOT)/usr/local/share/appdata/openscad.appdata.xml"

install:  install_target install_translation_fr install_translation_ru install_translation_de install_translation_cs install_translation_es install_examples install_libraries install_fonts install_colorschemes install_applications install_mimexml install_appdata install_icons install_man  FORCE

uninstall: uninstall_target uninstall_examples uninstall_libraries uninstall_fonts uninstall_colorschemes   FORCE

FORCE:


