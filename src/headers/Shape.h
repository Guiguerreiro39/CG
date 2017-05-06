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

	string texture_file; // remove it later (just for debugging purposes)
	GLuint buffers[3];
	GLuint texture;
	Material* colour_component;

	vector<Point*> vertex_list;
	vector<Point*> normal_list;
	vector<Point*> texture_list;

	public:
		Shape();
		Shape(vector<Point*>,vector<Point*>,vector<Point*>); 
		Shape(string,vector<Point*>,vector<Point*>,vector<Point*>);
		string getTextureFile();
		GLuint* getBuffers();
		GLuint getTexture();
		Material* getColourComponent();
		vector<Point*> getVertexList();
		vector<Point*> getNormalList();
		vector<Point*> getTextureList();
		void setTextureFile(string);
		void setTexture(GLuint);
		void setColourComponent(Material*);
		void setVertexList(vector<Point*>);
		void setNormalList(vector<Point*>);
		void setTextureList(vector<Point*>);
		
		void prepare();
		void loadTexture();
		void drawVertex3f(); // just for performance tests purposes
		void draw();
		virtual ~Shape();
};

#endif