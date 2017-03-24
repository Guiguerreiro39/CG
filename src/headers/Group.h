#ifndef __GROUP_H__
#define __GROUP_H__

#include <iostream> // TENHO DE TIRAR ISTO DAQUI !!!!! NÃO HÁ IO NESTA CLASSE!!!!
#include <string>
#include <vector>
#include "Shape.h"
#include "Translation.h"
#include "Rotation.h"
#include "Scale.h"

using namespace std;

class Group{

	int id;
	vector<string> group_shapes;
	vector<Group*> group_childs;
	Translation* translation;
	Rotation* rotation;
	Scale* scale;

	public:
		Group();
		Group(int);
		Group(vector<string>, vector<Group*>, Translation*, Rotation*, Scale*);
		int getID();
		vector<string> getShapes();
		vector<Group*> getChilds();
		Translation* getTranslation();
		Rotation* getRotation();
		Scale* getScale();
		void setShapes(vector<string>);
		void setChilds(vector<Group*>);
		void setTranslation(Translation*);
		void setRotation(Rotation*);
		void setScale(Scale*);
		void addChild(Group*);
		void print(); // TIRAR ISTO DAQUI 
		virtual ~Group();
};

#endif