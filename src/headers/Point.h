#ifndef __POINT_H__
#define __POINT_H__
#include <string>
using namespace std;

class Point{

	float x;
	float y;
	float z;

	public:
		Point();
		Point(float,float,float);
		float getX();
		float getY();
		float getZ();
		string print();
		string print2();
		virtual ~Point(void);
};

#endif