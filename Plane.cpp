#include "Plane.h"

vector<Vertex*> createPlane(float size){

	vector<Vertex*> vertex_list;
	float h = size/2; // para o plano ficar centrado na origem do referencial.

	vertex_list.push_back(new Vertex(h,0,h));
	vertex_list.push_back(new Vertex(h,0,-h));
	vertex_list.push_back(new Vertex(-h,0,h));

	vertex_list.push_back(new Vertex(-h,0,h));
	vertex_list.push_back(new Vertex(h,0,-h));
	vertex_list.push_back(new Vertex(-h,0,-h));

	return vertex_list;

}