#include "headers/Patch.h"

Patch::Patch(){
}

Patch::Patch(int n, vector<int> i, vector<Vertex*> v){
	number_points = n;
	indexes = i;
	control_points = v;
}

int Patch::getNumberPoints(){
	return number_points;
}

vector<int> Patch::getIndexes(){
	return indexes;
}

vector<Vertex*> Patch::getControlPoints(){
	return control_points;
}

void Patch::setNumberPoints(int n){
	number_points = n;
}

void Patch::setIndexes(vector<int> i){
	indexes = i;
}

void Patch::setControlPoints(vector<Vertex*> v){
	control_points = v;
}

Patch::~Patch(){
}