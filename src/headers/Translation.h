#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

#include <vector>
#include <math.h>
#include <GL/glut.h>

#include "Point.h"
#include "Operation.h"

using namespace std;

class Translation: public Operation{

	float time;
	float up[3];
	vector<Point*> points_list;
	vector<Point*> points_curv;

	public:
		Translation(float,float,float,float);
		float getTime();
		vector<Point*> getPoints();
		vector<Point*> getPointsCurv();
		vector<Point*> genPointsCurv();
		void getGlobalCatmullRomPoint(float, float*,float*, vector<Point*>);
		void setTime(float);
		void setPoints(vector<Point*>);
		void addPoint(Point*);
		void apply();
		virtual ~Translation();
};

#endif