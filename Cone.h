#ifndef __CONE_H__
#define __CONE_H__
#include <string>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vertex.h"
#include <vector>
using namespace std; 

vector<Vertex*> createCone(float radius, float height, int slice, int stack);

#endif