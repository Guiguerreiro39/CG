#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <string>
#include <vector>
#include <GL/glut.h>

#include "Vertex.h"

using namespace std;

class Shape{

	string name;
	GLuint vertex_buffer;
	vector<Vertex*> vertex_list;

	public:
		Shape();
		Shape(string,vector<Vertex*>);
		string getName();
		vector<Vertex*> getVertexList();
		GLuint getVertexBuffer();
		void prepare();
		void drawVertex3f(); // just for performance tests purposes
		void draw();
		virtual ~Shape();
};

#endif