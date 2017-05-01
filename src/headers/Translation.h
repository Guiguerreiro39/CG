#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

#include <vector>
#include <math.h>
#include <GL/glut.h>

#include "Vertex.h"

using namespace std;

class Translation{

	float x; 
	float y; 
	float z; 

	float time;
	float up[3];
	vector<Vertex*> points_list;
	vector<Vertex*> points_curv;

	public:
		Translation();
		Translation(float,float,float,float);
		float getX();
		float getY();
		float getZ();
		float getTime();
		vector<Vertex*> getPoints();
		vector<Vertex*> getPointsCurv();
		vector<Vertex*> genPointsCurv();
		void getGlobalCatmullRomPoint(float, float*,float*, vector<Vertex*>);
		void setX(float);
		void setY(float);
		void setZ(float);
		void setTime(float);
		void setPoints(vector<Vertex*>);
		void addPoint(Vertex*);
		void apply();
		Translation* clone() const;
		virtual ~Translation();
};

#endif