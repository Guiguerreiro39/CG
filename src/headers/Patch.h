#ifndef __PATCH_H__
#define __PATCH_H__

#include <vector>

#include "Point.h"

using namespace std;

class Patch{

	vector<Point*> control_points;

	public:
		Patch();
		Patch(vector<Point*>);
		vector<Point*> getControlPoints();
		void setControlPoints(vector<Point*>);
		void addVertex(Point*);
		virtual ~Patch();

};

#endif