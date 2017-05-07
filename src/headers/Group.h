
#ifndef __GROUP_H__
#define __GROUP_H__

#include <string>
#include <vector>

#include "Shape.h"
#include "Operation.h"
#include "Light.h"

using namespace std;

class Group{

	int id;
	vector<Shape*> group_shapes;
	vector<Group*> group_childs;
	vector<Operation*> group_operations;
	vector<Light*> group_lights;

	public:
		Group();
		Group(int);
		Group(vector<Shape*>, vector<Group*>, vector<Operation*>, vector<Light*>);
		int getID();
		vector<Shape*> getShapes();
		vector<Group*> getChilds();
		vector<Operation*> getOperations();
		vector<Light*> getLights();
		void setShapes(vector<Shape*>);
		void setChilds(vector<Group*>);
		void setOperations(vector<Operation*>);
		void setLights(vector<Light*>);
		void addChild(Group*);
		void addOperation(Operation*);
		virtual ~Group();
};

#endif

