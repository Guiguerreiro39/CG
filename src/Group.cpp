#include "headers/Group.h"

Group::Group(){
}

Group::Group(int n){
	id = n;
}

Group::Group(vector<string> shape_list, vector<Group*> group_list, Translation* t, Rotation* r, Scale* s){
	group_shapes = shape_list;
	group_childs = group_list;
	translation = t;
	rotation = r;
	scale = s;
}

int Group::getID(){
	return id;
}

vector<string> Group::getShapes(){
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

void Group::setShapes(vector<string> shape_list){
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

void Group::addChild(Group* child){
	group_childs.push_back(child);
}

void Group::print(){
	cout << "################# Grupo " << id << " #################" << endl;

	if(translation){
		cout << "Translation: " << translation->getX() << " | " << translation->getY() << " | " << translation->getZ()  << endl;
	}

	if(rotation){
		cout << "Rotation: " << rotation->getAngle() << " | " << rotation->getX() << " | " << rotation->getY() << " | " << rotation->getZ()  << endl;
	}
	
	if(scale){
		cout << "Scale: " << scale->getX() << " | " << scale->getY() << " | " << scale->getZ()  << endl;
	}

	cout << "Tamanho: " << group_shapes.size() << endl;
	cout << "Models: ";
	for(vector<string>::iterator it_lista = group_shapes.begin(); it_lista != group_shapes.end(); ++it_lista){
			cout << *it_lista << "; ";
	}
	cout << endl;

	cout << "Childs: ";
	for(vector<Group*>::iterator it = group_childs.begin(); it != group_childs.end(); ++it){
		cout << (*it)->getID() << "; ";
	}
	cout << endl;

	cout << "#################################################" <<endl;


} 

Group::~Group(){
}
