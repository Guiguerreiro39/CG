#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

#include <vector>
#include <math.h>
#include <GL/glut.h>

#include "Point.h"

using namespace std;

class Translation{

	float x; 
	float y; 
	float z; 

	float time;
	float up[3];
	vector<Point*> points_list;
	vector<Point*> points_curv;

	public:
		Translation();
		Translation(float,float,float,float);
		float getX();
		float getY();
		float getZ();
		float getTime();
		vector<Point*> getPoints();
		vector<Point*> getPointsCurv();
		vector<Point*> genPointsCurv();
		void getGlobalCatmullRomPoint(float, float*,float*, vector<Point*>);
		void setX(float);
		void setY(float);
		void setZ(float);
		void setTime(float);
		void setPoints(vector<Point*>);
		void addPoint(Point*);
		void apply();
		Translation* clone() const;
		virtual ~Translation();
};

#endif