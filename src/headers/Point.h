#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>
#include <string> 

using namespace std;

class Point{

	float x;
	float y;
	float z;

	public:
		Point();
		Point(float,float,float);
		Point(const Point &p);
		float getX();
		float getY();
		float getZ();
		string print(); // retirar
		string print2(); // retirar
		void incr(Point*);
		void vector_scale(float);
		void vector_cross(Point*);
		void vector_normalize();
		void sphericToCartesian(Point*);
		void cartesianToSpheric(Point*);
		virtual ~Point(void);
};

#endif