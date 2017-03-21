#ifndef __GROUP_H__
#define __GROUP_H__
#include <string>
#include <vector>
#include "Shape.h"
using namespace std;

class Group{

	string transformation;
	vector<Shape*> group_shapes;
	vector<Group*> group_childs;

	public:
		Group();
		Group(string, vector<Shape*>, vector<Group*>);
		string getTransformation();
		vector<Shape*> getShapes();
		vector<Group*> getChilds();
		void setTransformation(string);
		void setShapes(vector<Shape*>);
		void setChilds(vector<Group*>);
		virtual ~Group(void);
};

#endif