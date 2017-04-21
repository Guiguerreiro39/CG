#ifndef __FIGURES_H__
#define __FIGURES_H__

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>

#include "Vertex.h"

using namespace std; 

vector<Vertex*> createPlane(float size);
vector<Vertex*> createBox(float x, float y, float z, int div);
vector<Vertex*> createCone(float radius, float height, int slice, int stack);
vector<Vertex*> createSphere(float radius, int slice, int stack);
vector<Vertex*> createCylinder(float radius, float height, int slice, int stack);
vector<Vertex*> createTorus(float radiusIn, float radiusOut, int sides, int rings);

Vertex* evalBezierPatch(float,float*,float*,float*,float*); 

#endif