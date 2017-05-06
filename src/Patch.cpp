#include "headers/Patch.h"

Patch::Patch(){
}

Patch::Patch(vector<Point*> v){
	control_points = v;
}

vector<Point*> Patch::getControlPoints(){
	return control_points;
}

void Patch::setControlPoints(vector<Point*> v){
	control_points = v;
}

void Patch::addVertex(Point* v){
	control_points.push_back(v);
}

Patch::~Patch(){
}