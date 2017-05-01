#ifndef __ROTATION_H__
#define __ROTATION_H__

#include <GL/glut.h>

class Rotation{

	float angle;
	float time;
	float x, y, z;

	public:
		Rotation();
		Rotation(float,float,float,float,float);
		float getAngle();
		float getTime();
		float getX();
		float getY();
		float getZ();
		void setAngle(float);
		void setTime(float);
		void setX(float);
		void setY(float);
		void setZ(float);
		void apply();
		Rotation* clone() const;
		virtual ~Rotation();
};

#endif