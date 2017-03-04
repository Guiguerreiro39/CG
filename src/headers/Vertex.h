#ifndef __VERTEX_H__
#define __VERTEX_H__
#include <string>
using namespace std;

class Vertex{

	float x;
	float y;
	float z;

	public:
		Vertex();
		Vertex(float,float,float);
		float getX();
		float getY();
		float getZ();
		string print();
		virtual ~Vertex(void);
};

#endif