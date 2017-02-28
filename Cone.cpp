#include "Cone.h"

vector<Vertex*> createSphere(float radius, float height, int slice, int stack){

	vector<Vertex*> vertex_list;

	float alfa,x,z;
	float h = height;
	float l = sqrt(pow(h,2) + pow(radius,2))/stack;
	float t = radius/stack;

	for (int i = 0; i < stack; i++) {		
		for (int j = 0; j < slice; j++) {
			alfa = j*(2 * M_PI)/slice;
			if (i == 0){
				vertex_list.push_back(new Vertex(0,i*l,0));

				x = radius * sin(alfa + 2*M_PI/slice);
				z = radius * cos(alfa + 2*M_PI/slice);
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));
			}
			if (i < stack - 1) {
				x = (radius - ((i+1)*t)) * sin(alfa + 2*M_PI/slice);
				z = (radius - ((i+1)*t)) * cos(alfa + 2*M_PI/slice);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa);
				z = (radius - ((i+1)*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - (i*t)) * sin(alfa + 2*M_PI/slice);
				z = (radius - (i*t)) * cos(alfa + 2*M_PI/slice);
				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa + 2*M_PI/slice);
				z = (radius - ((i+1)*t)) * cos(alfa + 2*M_PI/slice);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
			}
			else {
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = (radius - (i*t)) * sin(alfa + 2*M_PI/slice);
				z = (radius - (i*t)) * cos(alfa + 2*M_PI/slice);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(0,(i+1)*l,0));
			}
		}
	}
	return vertex_list;
}
