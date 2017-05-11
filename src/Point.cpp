#include "headers/Point.h"

Point::Point(){
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

float Point::getX(){
	return x;
}

float Point::getY(){
	return y;
}

float Point::getZ(){
	return z;
}

string Point::print(){
	string res = to_string(x) + " " + to_string(y) + " " + to_string(z);
	return res;
}

string Point::print2(){
	string res = to_string(x) + " " + to_string(y);
	return res;
}

Point::~Point(void){
}

