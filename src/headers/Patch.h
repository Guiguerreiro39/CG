#ifndef __PATCH_H__
#define __PATCH_H__
#include <string>
#include <vector>

#include "Vertex.h"

using namespace std;

class Patch{

	int number_points;
	vector<int> indexes;
	vector<Vertex*> control_points;

	public:
		Patch();
		Patch(int, vector<int>, vector<Vertex*>);
		int getNumberPoints();
		vector<int> getIndexes();
		vector<Vertex*> getControlPoints();
		void setNumberPoints(int);
		void setIndexes(vector<int>);
		void setControlPoints(vector<Vertex*>);
		virtual ~Patch();

};

#endif