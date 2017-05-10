#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <GLUT/glut.h>
#include <iostream>

#include "Point.h"

class Light{

	bool isPoint;
	Point* point;

	public:
		Light();
		Light(bool, Point*);
		bool getType();
		Point* getPoint();
		void setType(bool);
		void setPoint(Point*);
		void draw();
		virtual ~Light();
};

#endif