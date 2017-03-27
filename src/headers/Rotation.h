#ifndef __ROTATION_H__
#define __ROTATION_H__

class Rotation{

	float angle;
	float x, y, z;

	public:
		Rotation();
		Rotation(float,float,float,float);
		float getAngle();
		float getX();
		float getY();
		float getZ();
		void setAngle(float);
		void setX(float);
		void setY(float);
		void setZ(float);
		Rotation* clone() const;
		virtual ~Rotation();
};

#endif