#include "headers/Shape.h"

Shape::Shape(){
}

Shape::Shape(string i, vector<Vertex*> list){
	name = i;
	vertex_list = list;
}

string Shape::getName(){
	return name;
}

vector<Vertex*> Shape::getVertexList(){
	return vertex_list;
}

GLuint Shape::getVertexBuffer(){
	return vertex_buffer;
}

void Shape::prepare(){

	int index = 0;
	float* vertex_array = (float*) malloc(sizeof(float) * vertex_list.size() * 3);

	for(vector<Vertex*>::const_iterator vertex_it = vertex_list.begin(); vertex_it != vertex_list.end(); ++vertex_it){					
		vertex_array[index] = (*vertex_it)->getX();
		vertex_array[index+1] = (*vertex_it)->getY();
		vertex_array[index+2] = (*vertex_it)->getZ();
		index+=3;
	}

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * index, vertex_array, GL_STATIC_DRAW);

	free(vertex_array);
}

void Shape::drawVertex3f(){ // Just for performance tests purposes

	float x,y,z;

	glBegin(GL_TRIANGLES);

	for(vector<Vertex*>::const_iterator vertex_it = vertex_list.begin(); vertex_it != vertex_list.end(); ++vertex_it){					
		x = (*vertex_it)->getX();
		y = (*vertex_it)->getY();
		z = (*vertex_it)->getZ();
		glVertex3f(x,y,z);
	}

	glEnd(); 
}

void Shape::draw(){
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, vertex_list.size()*3); // experimentar sem o *3 
}

Shape::~Shape(void){
}
