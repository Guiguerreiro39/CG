#include "headers/Group.h"

Group::Group(){
}

Group::Group(int n){
	id = n;
}

Group::Group(vector<Shape*> shape_list, vector<Group*> group_list, Translation* t, Rotation* r, Scale* s, Colour* c){
	group_shapes = shape_list;
	group_childs = group_list;
	translation = t;
	rotation = r;
	scale = s;
	colour = c;
}

int Group::getID(){
	return id;
}

vector<Shape*> Group::getShapes(){
	return group_shapes;
}

vector<Group*> Group::getChilds(){
	return group_childs;
}

Translation* Group::getTranslation(){
	return translation;
}

Rotation* Group::getRotation(){
	return rotation;
}

Scale* Group::getScale(){
	return scale;
}

Colour* Group::getColour(){
	return colour;
}

void Group::setShapes(vector<Shape*> shape_list){
	group_shapes = shape_list;
}

void Group::setChilds(vector<Group*> group_list){
	group_childs = group_list;
}

void Group::setTranslation(Translation* t){
	translation = t;
}

void Group::setRotation(Rotation* r){
	rotation = r;
}

void Group::setScale(Scale* s){
	scale = s;
}

void Group::setColour(Colour* c){
	colour = c;
}

void Group::addChild(Group* child){
	group_childs.push_back(child);
}

Group::~Group(){
}
