#pragma once

#include <iostream>
#include "Tree.h"
#include "Camera.h"
#include "memory.h"

#ifdef ENABLE_CGAL

enum FileFormat {
	OPENSCAD_STL,
	OPENSCAD_OFF,
	OPENSCAD_AMF,
	OPENSCAD_DXF,
	OPENSCAD_SVG
};

// void exportFile(const class Geometry *root_geom, std::ostream &output, FileFormat format);
void exportFileByName(const class Geometry *root_geom, FileFormat format, const char *name2open, const char *name2display);

void export_mesh( const class Geometry *root_geom, std::stringstream &output );
void buffer_stl(const class CGAL_Nef_polyhedron *root_N, std::stringstream &output );
void buffer_stl( const class PolySet &ps , std::stringstream &output );

#endif // ENABLE_CGAL

#ifdef DEBUG
void export_stl(const class PolySet &ps, std::ostream &output);
#endif

