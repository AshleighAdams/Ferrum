#pragma once
#ifndef F_BASE_H
#define F_BASE_H

// STL stuff here
#include <string>
using namespace std;

// OpenGL
#include "GL/glew.h"
#include "GL/gl.h"

// SFML stuff here
#include <SFML/Graphics.hpp>
typedef sf::Vector3<double> Vector;

// Our stuff now
#include "Math/Angle.h"


// Helper stuff
//TODO: Implement this properly
struct Vertex
{
	float x, y, z;        //Vertex
	float nx, ny, nz;     //Normal
	float s0, t0;         //Texcoord0
};

#endif // F_BASE_H
