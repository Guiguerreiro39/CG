#include "headers/Shape.h"

Shape::Shape(){
}

Shape::Shape(vector<Point*> v_list, vector<Point*> n_list, vector<Point*> t_list){

	buffers_size[0] = v_list.size();
	buffers_size[1] = n_list.size();
	buffers_size[2] = t_list.size();
	prepare(v_list, n_list, t_list);
}

Shape::Shape(string texture_file, vector<Point*> v_list, vector<Point*> n_list, vector<Point*> t_list){

	buffers_size[0] = v_list.size();
	buffers_size[1] = n_list.size();
	buffers_size[2] = t_list.size();
	prepare(v_list, n_list, t_list);
	loadTexture(texture_file);
}

GLuint* Shape::getBuffers(){
	return buffers;
}

GLuint Shape::getTexture(){
	return texture;
}

Material* Shape::getColourComponent(){
	return colour_component;
}

void Shape::setTexture(GLuint t){
	texture = t;
}

void Shape::setColourComponent(Material* c){
	colour_component = c;
}

void Shape::prepare(vector<Point*> vertex_list, vector<Point*> normal_list, vector<Point*> texture_list){

	int index = 0;
	float* vertex_array = (float*) malloc(sizeof(float) * vertex_list.size() * 3);
	float* normal_array = (float*) malloc(sizeof(float) * normal_list.size() * 3);
	float* texture_array = (float*) malloc(sizeof(float) * texture_list.size() * 2);

	for(vector<Point*>::const_iterator vertex_it = vertex_list.begin(); vertex_it != vertex_list.end(); ++vertex_it){					
		vertex_array[index] = (*vertex_it)->getX();
		vertex_array[index+1] = (*vertex_it)->getY();
		vertex_array[index+2] = (*vertex_it)->getZ();
		index+=3;
	}

	index = 0;
	for(vector<Point*>::const_iterator normal_it = normal_list.begin(); normal_it != normal_list.end(); ++normal_it){					
		normal_array[index] = (*normal_it)->getX();
		normal_array[index+1] = (*normal_it)->getY();
		normal_array[index+2] = (*normal_it)->getZ();
		index+=3;
	}

	index = 0;
	for(vector<Point*>::const_iterator texture_it = texture_list.begin(); texture_it != texture_list.end(); ++texture_it){					
		texture_array[index] = (*texture_it)->getX();
		texture_array[index+1] = (*texture_it)->getY();
		index+=2;
	}

	glGenBuffers(3, buffers); 
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffers_size[0] * 3, vertex_array, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffers_size[1] * 3, normal_array, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffers_size[2] * 2, texture_array, GL_STATIC_DRAW);

	free(vertex_array);
	free(normal_array);
	free(texture_array);
}

void Shape::loadTexture(string texture_file){

	unsigned int t,tw,th;
	unsigned char *texData;
	
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	ilGenImages(1, &t);
	ilBindImage(t);
	ilLoadImage((ILstring) texture_file.c_str());
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	texData = ilGetData(); 
	
	glGenTextures(1, &texture); 
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glBindTexture(GL_TEXTURE_2D, 0); 
}

void Shape::draw(){

	colour_component->draw();

	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	if(buffers_size[1]){
		glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
		glNormalPointer(GL_FLOAT, 0, 0);
	}

	if(buffers_size[2]){
		glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
		glTexCoordPointer(2, GL_FLOAT, 0, 0); 
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	
	glDrawArrays(GL_TRIANGLES, 0, buffers_size[0] * 3);
	glBindTexture(GL_TEXTURE_2D, 0);
 
}

Shape::~Shape(void){
}
