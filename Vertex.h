#ifndef __VERTEX_H__
#define __VERTEX_H__

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
		virtual ~Vertex(void);
};

#endif