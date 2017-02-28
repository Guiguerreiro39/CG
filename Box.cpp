#include "Box.h"

vector<Vertex*> createBox(float cX, float cY, float cZ, int div){

	vector<Vertex*> vertex_list;
	float x = cX/2;
	float y = cY/2;
	float z = cz/2;
	float shiftX = (float)cX/div;
	float shiftY = (float)cY/div;
	float shiftZ = (float)cZ/div;

	for(int i=0;i<div;i++){
		for(int j=0;j<div;j++){
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),-z));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z + (j*shiftX)));
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z + (j*shiftX)));
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));	
		}
	}
	return vertex_list;
}