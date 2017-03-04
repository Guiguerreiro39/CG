#ifndef __SPHERE_H__
#define __SPHERE_H__
#include <string>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vertex.h"
#include <vector>
using namespace std; 

vector<Vertex*> createSphere(float radius, int slice, int stack);

#endif