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

Point::Point(const Point &p){
	x = p.x;
	y = p.y;
	z = p.z;
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

void Point::setX(float p){
    x = p;
}

void Point::setY(float p){
    y=p;
}

void Point::setZ(float p){
    z=p;
}

string Point::print(){
	string res = to_string(x) + " " + to_string(y) + " " + to_string(z);
	return res;
}

string Point::print2(){
	string res = to_string(x) + " " + to_string(y);
	return res;
}

void Point::incr(Point* p){
    x = x + p->getX();
    y = y + p->getY();
    z = z + p->getZ();
}


void Point::vector_scale(float k){
    x *= k;
    y *= k;
    z *= k;
}

void Point::vector_cross(Point* p){
    x = y * p->getZ() - z * p->getY();
    y = z * p->getX() - x * p->getZ();
    z = x * p->getY() - y * p->getX();
}

void Point::vector_normalize(){
    float len = sqrt(x*x + y*y + z*z);
     
    if(len <= 0.0001){
        x = 0;
        y = 0;
        z = 0;
        return;
    }

    x /= len;
    y /= len;
    z /= len;
}

void Point::sphericToCartesian(Point* center){
    float rad = x;
    float lat = y;
    float lon = z;

    x = rad * sin(lat) * cos(lon) - center->getX();
    z = rad * sin(lat) * sin(lon) - center->getY();
    y = rad * cos(lat)            - center->getZ();
}

void Point::cartesianToSpheric(Point* center){
    float X2 = x - center->getX();
    float Y2 = y - center->getY();
    float Z2 = z - center->getZ();

    x = sqrt(pow(X2, 2) + pow(Y2, 2) + pow(Z2, 2));
    y = atan(Z2 / X2);
    z = acos(Y2 / x);
}

Point::~Point(void){
}

