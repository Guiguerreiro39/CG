#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <string>
#include <vector>
#include <GL/glut.h>
#include <IL/il.h>

#include "Point.h"
#include "Material.h"

using namespace std;

class Shape{

	int buffers_size[3];
	GLuint buffers[3];
	GLuint texture;
	Material* colour_component;

	public:
		Shape();
		Shape(vector<Point*>,vector<Point*>,vector<Point*>); 
		Shape(string,vector<Point*>,vector<Point*>,vector<Point*>);

		GLuint* getBuffers();
		GLuint getTexture();
		Material* getColourComponent();
		void setTexture(GLuint);
		void setColourComponent(Material*);
		
		void prepare(vector<Point*>, vector<Point*>, vector<Point*>);
		void loadTexture(string);
		void draw();
		virtual ~Shape();
};

#endif