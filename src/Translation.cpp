#include "headers/Translation.h"

Translation::Translation(){
}

Translation::Translation(float a, float b, float c, float t){
	x = a;
	y = b;
	z = c;
	time = t;
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

float Translation::getTime(){
	return time;
}

vector<Vertex*> Translation::getPoints(){
	return points_list;
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

void Translation::setTime(float t){
	time = t;
}

void Translation::setPoints(vector<Vertex*> v){
	points_list = v;
}

void Translation::addPoint(Vertex* v){
	points_list.push_back(v);
}

Translation* Translation::clone() const{
	return new Translation(x,y,z,time);
}

Translation::~Translation(){
}