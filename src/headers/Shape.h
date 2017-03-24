#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <string>
#include <vector>
#include "Vertex.h"

using namespace std;

class Shape{

	int id;
	vector<Vertex*> vertex_list;

	public:
		Shape();
		Shape(int,vector<Vertex*>);
		int getID();
		vector<Vertex*> getVertexList();
		virtual ~Shape();
};

#endif