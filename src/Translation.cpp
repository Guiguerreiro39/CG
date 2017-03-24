#include "headers/Translation.h"

Translation::Translation(){
}

Translation::Translation(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

float Translation::getX(){
	return x;
}

float Translation::getY(){
	return y;
}

float Translation::getZ(){
	return z;
}

void Translation::setX(float a){
	x = a;
}

void Translation::setY(float b){
	y = b;
}

void Translation::setZ(float c){
	z = c;
}

Translation* Translation::clone(){
	return new Translation(x,y,z);
}

Translation::~Translation(){
}