#ifndef __PATCH_H__
#define __PATCH_H__

#include <vector>
#include <iostream>

#include "Vertex.h"

using namespace std;

class Patch{

	vector<int> indexes;
	vector<Vertex*> control_points;

	public:
		Patch();
		Patch(vector<int>, vector<Vertex*>);
		vector<int> getIndexes();
		vector<Vertex*> getControlPoints();
		void setIndexes(vector<int>);
		void setControlPoints(vector<Vertex*>);
		void addIndex(int);
		void addVertex(Vertex*);
		void print();
		virtual ~Patch();

};

#endif