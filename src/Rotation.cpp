#include "headers/Rotation.h"

Rotation::Rotation(){
}

Rotation::Rotation(float ang, float a, float b, float c){
	angle = ang;
	x = a;
	y = b;
	z = c;
}

float Rotation::getAngle(){
	return angle;
}

float Rotation::getX(){
	return x;
}

float Rotation::getY(){
	return y;
}

float Rotation::getZ(){
	return z;
}

void Rotation::setAngle(float ang){
	angle = ang;
}

void Rotation::setX(float a){
	x = a;
}

void Rotation::setY(float b){
	y = b;
}

void Rotation::setZ(float c){
	z = c;
}

Rotation* Rotation::clone() const{
	return new Rotation(angle,x,y,z);
}

Rotation::~Rotation(){
}