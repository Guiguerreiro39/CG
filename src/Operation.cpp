#include "headers/Operation.h"

Operation::Operation(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

float Operation::getX(){
	return x;
}

float Operation::getY(){
	return y;
}

float Operation::getZ(){
	return z;
}

void Operation::setX(float a){
	x = a;
}

void Operation::setY(float b){
	y = b;
}

void Operation::setZ(float c){
	z = c;
}