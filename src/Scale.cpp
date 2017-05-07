#include "headers/Scale.h"

Scale::Scale(float a, float b, float c) : Operation(a,b,c){
}

void Scale::apply(){
	glScalef(getX(),getY(),getZ());
}

Scale::~Scale(){
}