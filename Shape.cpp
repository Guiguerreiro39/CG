#include "Shape.h"

Shape::Shape(){
}

Shape::Shape(int i, vector<Vertex*> list){
	id = i;
	vertex_list = list;
}

int Shape::getID(){
	return id;
}

vector<Vertex*> Shape::getVertexList(){
	return vertex_list;
}

Shape::~Shape(void){
}
