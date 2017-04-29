#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

#include <vector>

#include "Vertex.h"

using namespace std;

class Translation{

	float x; 
	float y; 
	float z; 

	float time;
	vector<Vertex*> points_list;

	public:
		Translation();
		Translation(float,float,float);
		float getX();
		float getY();
		float getZ();
		float getTime();
		vector<Vertex*> getPoints();
		void setX(float);
		void setY(float);
		void setZ(float);
		void setTime(float);
		void setPoints(vector<Vertex*>);
		void addPoint(Vertex*);
		Translation* clone() const;
		virtual ~Translation();
};

#endif