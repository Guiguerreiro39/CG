#ifndef __FIGURES_H__
#define __FIGURES_H__

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>
#include <iostream>

#include "Patch.h"
#include "Vertex.h"

using namespace std; 

// Figures
vector<Vertex*> createPlane(float size);
vector<Vertex*> createBox(float x, float y, float z, int div);
vector<Vertex*> createCone(float radius, float height, int slice, int stack);
vector<Vertex*> createSphere(float radius, int slice, int stack);
vector<Vertex*> createCylinder(float radius, float height, int slice, int stack);
vector<Vertex*> createTorus(float radiusIn, float radiusOut, int sides, int rings);

// Patches
Vertex* evalBezierCurve(float t, Vertex* p1, Vertex* p2, Vertex* p3, Vertex* p4);
Vertex* evalBezierPatch(float u, float v, vector<Vertex*> control_points);
vector<Vertex*> renderBezierPatch(int divs, vector<Patch*> patch_list);

#endif