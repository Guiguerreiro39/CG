#include "headers/Shape.h"

Shape::Shape(){
}

Shape::Shape(string i, vector<Vertex*> v_list, vector<Vertex*> n_list, vector<Vertex*> t_list){
	name = i;
	vertex_list = v_list;
	normal_list = n_list;
	texture_list = t_list;
}

string Shape::getName(){
	return name;
}

GLuint* Shape::getBuffers(){
	return buffers;
}

Material* Shape::getColourComponent(){
	return colour_component;
}

vector<Vertex*> Shape::getVertexList(){
	return vertex_list;
}

vector<Vertex*> Shape::getNormalList(){
	return normal_list;
}

vector<Vertex*> Shape::getTextureList(){
	return texture_list;
}

void Shape::setName(string t){
	name = t;
}

void Shape::setColourComponent(Material* c){
	colour_component = c;
}

void Shape::setVertexList(vector<Vertex*> v){
	vertex_list = v;
}

void Shape::setNormalList(vector<Vertex*> v){
	normal_list = v;
}

void Shape::setTextureList(vector<Vertex*> v){
	texture_list = v;
}


void Shape::prepare(){

	int index = 0;
	float* vertex_array = (float*) malloc(sizeof(float) * vertex_list.size() * 3);
	float* normal_array = (float*) malloc(sizeof(float) * normal_list.size() * 3);
	float* texture_array = (float*) malloc(sizeof(float) * texture_list.size() * 3);

	for(vector<Vertex*>::const_iterator vertex_it = vertex_list.begin(); vertex_it != vertex_list.end(); ++vertex_it){					
		vertex_array[index] = (*vertex_it)->getX();
		vertex_array[index+1] = (*vertex_it)->getY();
		vertex_array[index+2] = (*vertex_it)->getZ();
		index+=3;
	}

	index = 0;
	for(vector<Vertex*>::const_iterator normal_it = normal_list.begin(); normal_it != normal_list.end(); ++normal_it){					
		normal_array[index] = (*normal_it)->getX();
		normal_array[index+1] = (*normal_it)->getY();
		normal_array[index+2] = (*normal_it)->getZ();
		index+=3;
	}

	index = 0;
	for(vector<Vertex*>::const_iterator texture_it = texture_list.begin(); texture_it != texture_list.end(); ++texture_it){					
		texture_array[index] = (*texture_it)->getX();
		texture_array[index+1] = (*texture_it)->getY();
		texture_array[index+2] = (*texture_it)->getZ();
		index+=3;
	}

	glGenBuffers(3, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_list.size() * 3, vertex_array, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normal_list.size() * 3, normal_array, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texture_list.size() * 3, texture_array, GL_STATIC_DRAW);

	free(vertex_array);
	free(normal_array);
	free(texture_array);

	// makeTexture!!
}

void Shape::createTexture(){

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

	colour_component->draw();

	//glBindTexture(GL_TEXTURE_2D, textureID);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glNormalPointer(GL_FLOAT, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glTexCoordPointer(2, GL_FLOAT, 0, 0); 

	glDrawArrays(GL_TRIANGLES, 0, vertex_list.size()*3); 
}

Shape::~Shape(void){
}
