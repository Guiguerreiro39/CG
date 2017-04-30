#include "headers/Patch.h"

Patch::Patch(){
}

Patch::Patch(vector<Vertex*> v){
	control_points = v;
}

vector<Vertex*> Patch::getControlPoints(){
	return control_points;
}

void Patch::setControlPoints(vector<Vertex*> v){
	control_points = v;
}

void Patch::addVertex(Vertex* v){
	control_points.push_back(v);
}

Patch::~Patch(){
}