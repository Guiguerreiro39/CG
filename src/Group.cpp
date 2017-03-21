#include "headers/Group.h"

Group::Group(){
}

Group::Group(string t, vector<Shape*> shape_list, vector<Group*> group_list){
	transformation = t;
	group_shapes = shape_list;
	group_childs = group_list;
}

string Group::getTransformation(){
	return transformation;
}

vector<Shape*> Group::getShapes(){
	return group_shapes;
}

vector<Group*> Group::getChilds(){
	return group_childs;
}

void Group::setTransformation(string t){
	transformation = t;
}

void Group::setShapes(vector<Shape*> shape_list){
	group_shapes = shape_list;
}

void Group::setChilds(vector<Group*> group_list){
	group_childs = group_list;
}

Group::~Group(void){
}
