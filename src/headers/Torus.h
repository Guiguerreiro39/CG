#ifndef __TORUS_H__
#define __TORUS_H__
#include <string>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vertex.h"
#include <vector>
using namespace std; 

vector<Vertex*> createTorus(float radiusIn, float radiusOut, int sides,int rings );

#endif