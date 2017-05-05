#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <string>
#include <vector>
#include <GL/glut.h>

#include "Vertex.h"
#include "Material.h"

using namespace std;

class Shape{

	string name; // remove it later (just for debugging purposes)
	GLuint buffers[3];
	Material* colour_component;

	vector<Vertex*> vertex_list;
	vector<Vertex*> normal_list;
	vector<Vertex*> texture_list;

	public:
		Shape();
		Shape(string,vector<Vertex*>,vector<Vertex*>,vector<Vertex*>); 
		string getName();
		GLuint* getBuffers();
		Material* getColourComponent();
		vector<Vertex*> getVertexList();
		vector<Vertex*> getNormalList();
		vector<Vertex*> getTextureList();
		void setName(string);
		void setColourComponent(Material*);
		void setVertexList(vector<Vertex*>);
		void setNormalList(vector<Vertex*>);
		void setTextureList(vector<Vertex*>);
		void prepare();
		void createTexture();
		void drawVertex3f(); // just for performance tests purposes
		void draw();
		virtual ~Shape();
};

#endif