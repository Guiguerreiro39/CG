#ifndef __SCALE_H__
#define __SCALE_H__

#include <GL/glut.h>

class Scale{

	float x;
	float y;
	float z;

	public:
		Scale();
		Scale(float,float,float);
		float getX();
		float getY();
		float getZ();
		void setX(float);
		void setY(float);
		void setZ(float);
		void apply();
		Scale* clone() const;
		virtual ~Scale();
};

#endif