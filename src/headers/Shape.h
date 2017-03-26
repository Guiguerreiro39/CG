#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <string>
#include <vector>
#include "Vertex.h"

using namespace std;

class Shape{

	string name;
	vector<Vertex*> vertex_list;

	public:
		Shape();
		Shape(string,vector<Vertex*>);
		string getName();
		vector<Vertex*> getVertexList();
		virtual ~Shape();
};

#endif