#include "headers/Group.h"

Group::Group(){
}

Group::Group(int n){
	id = n;
}

Group::Group(vector<Shape*> shape_list, vector<Group*> group_list, vector<Operation*> operation_list, vector<Light*> light_list){
	group_shapes = shape_list;
	group_childs = group_list;
	group_operations = operation_list;
	group_lights = light_list;
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

vector<Operation*> Group::getOperations(){
	return group_operations;
}

vector<Light*> Group::getLights(){
	return group_lights;
}

void Group::setShapes(vector<Shape*> shape_list){
	group_shapes = shape_list;
}

void Group::setChilds(vector<Group*> group_list){
	group_childs = group_list;
}

void Group::setOperations(vector<Operation*> operation_list){
	group_operations = operation_list;
}

void Group::setLights(vector<Light*> light_list){
	group_lights = light_list;
}

void Group::addOperation(Operation* operation){
	group_operations.push_back(operation);
}

void Group::addChild(Group* child){
	group_childs.push_back(child);
}

Group::~Group(){
}
