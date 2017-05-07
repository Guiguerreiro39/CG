#include "headers/Rotation.h"

Rotation::Rotation(float ang, float t, float a, float b, float c) : Operation(a,b,c){
	angle = ang;
	time = t;
}

void Rotation::apply(){
	float r, gr;

	if(time!=0){
		r = glutGet(GLUT_ELAPSED_TIME) % (int)(time * 1000);
		gr = (r*360) / (time * 1000);
		glRotatef(gr,getX(),getY(),getZ());
	}
	else glRotatef(angle,getX(),getY(),getZ());
}

float Rotation::getAngle(){
	return angle;
}

float Rotation::getTime(){
	return time;
}

void Rotation::setAngle(float ang){
	angle = ang;
}

void Rotation::setTime(float t){
	time = t;
}

Rotation::~Rotation(){
}