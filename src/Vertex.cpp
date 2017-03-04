#include "headers/Vertex.h"

Vertex::Vertex(){
	x = 0;
	y = 0;
	z = 0;
}

Vertex::Vertex(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

float Vertex::getX(){
	return x;
}

float Vertex::getY(){
	return y;
}

float Vertex::getZ(){
	return z;
}

string Vertex::print(){
	string res = to_string(x) + " " + to_string(y) + " " + to_string(z);
	return res;
}

Vertex::~Vertex(void){
}

