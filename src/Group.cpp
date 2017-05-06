#include "headers/Group.h"

Group::Group(){
}

Group::Group(int n){
	id = n;
}

Group::Group(vector<Shape*> shape_list, vector<Group*> group_list, vector<Light*> light_list, Translation* t, Rotation* r, Scale* s){
	group_shapes = shape_list;
	group_childs = group_list;
	group_lights = light_list;
	translation = t;
	rotation = r;
	scale = s;
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

vector<Light*> Group::getLights(){
	return group_lights;
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

void Group::setShapes(vector<Shape*> shape_list){
	group_shapes = shape_list;
}

void Group::setChilds(vector<Group*> group_list){
	group_childs = group_list;
}

void Group::setLights(vector<Light*> light_list){
	group_lights = light_list;
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

void Group::addChild(Group* child){
	group_childs.push_back(child);
}

Group::~Group(){
}
