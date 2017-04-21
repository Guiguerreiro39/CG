#include "headers/Patch.h"

Patch::Patch(){
}

Patch::Patch(vector<int> i, vector<Vertex*> v){
	indexes = i;
	control_points = v;
}

vector<int> Patch::getIndexes(){
	return indexes;
}

vector<Vertex*> Patch::getControlPoints(){
	return control_points;
}

void Patch::setIndexes(vector<int> i){
	indexes = i;
}

void Patch::setControlPoints(vector<Vertex*> v){
	control_points = v;
}

void Patch::addIndex(int n){
	indexes.push_back(n);
}

void Patch::addVertex(Vertex* v){
	control_points.push_back(v);
}

void Patch::print(){
	cout << "____________________" << endl;
	cout << "Índices: ";
	for(int i=0; i<indexes.size(); i++) cout << indexes[i] << " , ";
	cout << endl;
	cout << "____________________" << endl;
	for(int i=0; i<control_points.size(); i++){
		Vertex* v = control_points[i];
		cout << v->getX() << " | " << v->getY() << " | " << v->getZ() << endl;
	}
	cout << "____________________" << endl;
}

Patch::~Patch(){
}