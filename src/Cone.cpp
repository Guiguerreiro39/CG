#include "headers/Cone.h"

vector<Vertex*> createCone(float radius, float height, int slice, int stack){

	vector<Vertex*> vertex_list;

	float alfa,x,z;
	float h = height;
	float l = sqrt(pow(h,2) + pow(radius,2))/stack;
	float t = radius/stack;
	float dimSide = (2*M_PI)/slice;

	for (int i = 0; i < stack; i++) {		
		for (int j = 0; j < slice; j++) {
			alfa = j * dimSide;
			if (i == 0){
				// desenhar a base
				vertex_list.push_back(new Vertex(0,0,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,0,z));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Vertex(x,0,z));
			}
			if (i < stack - 1) {
				// desenhar 2 triangulos para um lado (slice)
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa);
				z = (radius - ((i+1)*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
			}
			else {
				// desenhar o topo do cone
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(0,(i+1)*l,0));
			}
		}
	}
	return vertex_list;
}
