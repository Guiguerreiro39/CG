#include "headers/Light.h"

Light::Light(){
}

Light::Light(bool type, Point* p){
	isPoint = type;
	point = p;
}

bool Light::getType(){
	return isPoint;
}

Point* Light::getPoint(){
	return point;
}

void Light::setType(bool type){
	isPoint = type;
}

void Light::setPoint(Point* p){
	point = p;
}

void Light::draw(){

	GLfloat amb[4] = {0.2, 0.2, 0.2, 1.0};
	GLfloat diff[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat pos[4] = {point->getX(), point->getY() , point->getZ(), (float) isPoint};

	// light position
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	
	// light colors
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
}

Light::~Light(){
}