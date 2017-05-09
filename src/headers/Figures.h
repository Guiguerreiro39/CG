#ifndef __FIGURES_H__
#define __FIGURES_H__

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>
#include <iostream>

#include "Patch.h"
#include "Point.h"

using namespace std; 

// Figures
vector<Point*> createPlane(float size, vector<Point*> *normal_list, vector<Point*> *texture_list);
vector<Point*> createBox(float x, float y, float z, int div, vector<Point*> *normal_list, vector<Point*> *texture_list);
vector<Point*> createCone(float radius, float height, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list);
vector<Point*> createSphere(float radius, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list);
vector<Point*> createCylinder(float radius, float height, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list);
vector<Point*> createTorus(float radiusIn, float radiusOut, int sides, int rings, vector<Point*> *normal_list, vector<Point*> *texture_list);

// Patches
Point* evalBezierCurve(float t, Point* p1, Point* p2, Point* p3, Point* p4);
Point* evalBezierPatch(float u, float v, vector<Point*> control_points);
vector<Point*> renderBezierPatch(int divs, vector<Patch*> patch_list);

#endif