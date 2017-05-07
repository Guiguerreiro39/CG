#ifndef __ROTATION_H__
#define __ROTATION_H__

#include <GL/glut.h>
#include "Operation.h"

class Rotation: public Operation {

	float angle;
	float time;

	public:
		Rotation(float,float,float,float,float);
		float getAngle();
		float getTime();
		void setAngle(float);
		void setTime(float);
		void apply();
		virtual ~Rotation();
};

#endif