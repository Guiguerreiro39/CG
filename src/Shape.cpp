#include "headers/Shape.h"

Shape::Shape(){
}

Shape::Shape(string i, vector<Vertex*> list){
	name = i;
	vertex_list = list;
}

string Shape::getName(){
	return name;
}

vector<Vertex*> Shape::getVertexList(){
	return vertex_list;
}

Shape::~Shape(void){
}
