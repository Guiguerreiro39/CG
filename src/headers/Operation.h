#ifndef __OPERATION_H__
#define __OPERATION_H__

class Operation{

	float x; 
	float y; 
	float z; 

	public:
		Operation(float, float, float);
		float getX();
		float getY();
		float getZ();
		void setX(float);
		void setY(float);
		void setZ(float);
		virtual void apply() = 0;
};

#endif