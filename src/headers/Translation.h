#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

class Translation{

	float x;
	float y;
	float z;

	public:
		Translation();
		Translation(float,float,float);
		float getX();
		float getY();
		float getZ();
		void setX(float);
		void setY(float);
		void setZ(float);
		Translation* clone();
		virtual ~Translation();
};

#endif