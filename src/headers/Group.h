
#ifndef __GROUP_H__
#define __GROUP_H__

#include <string>
#include <vector>
#include "Shape.h"
#include "Translation.h"
#include "Rotation.h"
#include "Scale.h"
#include "Colour.h"

using namespace std;

class Group{

	int id;
	vector<Shape*> group_shapes;
	vector<Group*> group_childs;
	Translation* translation;
	Rotation* rotation;
	Scale* scale;
	Colour* colour;

	public:
		Group();
		Group(int);
		Group(vector<Shape*>, vector<Group*>, Translation*, Rotation*, Scale*, Colour*);
		int getID();
		vector<Shape*> getShapes();
		vector<Group*> getChilds();
		Translation* getTranslation();
		Rotation* getRotation();
		Scale* getScale();
		Colour* getColour();
		void setShapes(vector<Shape*>);
		void setChilds(vector<Group*>);
		void setTranslation(Translation*);
		void setRotation(Rotation*);
		void setScale(Scale*);
		void setColour(Colour*);
		void addChild(Group*);
		virtual ~Group();
};

#endif

