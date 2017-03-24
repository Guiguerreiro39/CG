#include "headers/Scale.h"

Scale::Scale(){
}

Scale::Scale(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

float Scale::getX(){
	return x;
}

float Scale::getY(){
	return y;
}

float Scale::getZ(){
	return z;
}

void Scale::setX(float a){
	x = a;
}

void Scale::setY(float b){
	y = b;
}

void Scale::setZ(float c){
	z = c;
}

Scale* Scale::clone(){
	return new Scale(x,y,z);
}

Scale::~Scale(){
}