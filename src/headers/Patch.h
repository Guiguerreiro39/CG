#ifndef __PATCH_H__
#define __PATCH_H__

#include <vector>

#include "Vertex.h"

using namespace std;

class Patch{

	vector<Vertex*> control_points;

	public:
		Patch();
		Patch(vector<Vertex*>);
		vector<Vertex*> getControlPoints();
		void setControlPoints(vector<Vertex*>);
		void addVertex(Vertex*);
		virtual ~Patch();

};

#endif