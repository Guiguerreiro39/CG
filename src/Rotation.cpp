#include "headers/Rotation.h"

Rotation::Rotation(){
}

Rotation::Rotation(float ang, float t, float a, float b, float c){
	angle = ang;
	time = t;
	x = a;
	y = b;
	z = c;
}

void Rotation::apply(){
	float r, gr;

	if(time!=0){
		r = glutGet(GLUT_ELAPSED_TIME) % (int)(time * 1000);
		gr = (r*360) / (time * 1000);
		glRotatef(gr,x,y,z);
	}
	else glRotatef(angle,x,y,z);
}

float Rotation::getAngle(){
	return angle;
}

float Rotation::getTime(){
	return time;
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

void Rotation::setTime(float t){
	time = t;
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
	return new Rotation(angle,time,x,y,z);
}

Rotation::~Rotation(){
}