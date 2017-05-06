
#ifndef __GROUP_H__
#define __GROUP_H__

#include <string>
#include <vector>

#include "Shape.h"
#include "Translation.h"
#include "Rotation.h"
#include "Scale.h"
#include "Light.h"

using namespace std;

class Group{

	int id;
	vector<Shape*> group_shapes;
	vector<Group*> group_childs;
	vector<Light*> group_lights;

	Translation* translation;
	Rotation* rotation;
	Scale* scale;

	public:
		Group();
		Group(int);
		Group(vector<Shape*>, vector<Group*>, vector<Light*>, Translation*, Rotation*, Scale*);
		int getID();
		vector<Shape*> getShapes();
		vector<Group*> getChilds();
		vector<Light*> getLights();
		Translation* getTranslation();
		Rotation* getRotation();
		Scale* getScale();
		void setShapes(vector<Shape*>);
		void setChilds(vector<Group*>);
		void setLights(vector<Light*>);
		void setTranslation(Translation*);
		void setRotation(Rotation*);
		void setScale(Scale*);
		void addChild(Group*);
		virtual ~Group();
};

#endif

