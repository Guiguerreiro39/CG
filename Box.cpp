#include "Box.h"

vector<Vertex*> createBox(float cX, float cY, float cZ){

	vector<Vertex*> vertex_list;
	float x = cX/2;
	float y = cY/2;
	float z = cz/2;
	
	vertex_list.push_back(new Vertex(x,0,z));
	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(0,0,z));

	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(0,y,z));
	vertex_list.push_back(new Vertex(0,0,z));

	vertex_list.push_back(new Vertex(x,0,-z));
	vertex_list.push_back(new Vertex(0,0,-z));
	vertex_list.push_back(new Vertex(x,y,-z));

	vertex_list.push_back(new Vertex(x,y,-z));
	vertex_list.push_back(new Vertex(0,0,-z));
	vertex_list.push_back(new Vertex(0,y,-z));

	vertex_list.push_back(new Vertex(x,0,z));
	vertex_list.push_back(new Vertex(x,0,-z));
	vertex_list.push_back(new Vertex(x,y,z));

	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(x,0,-z));
	vertex_list.push_back(new Vertex(x,y,-z));

	vertex_list.push_back(new Vertex(0,0,z));
	vertex_list.push_back(new Vertex(0,y,z));
	vertex_list.push_back(new Vertex(0,0,-z));

	vertex_list.push_back(new Vertex(0,y,z));
	vertex_list.push_back(new Vertex(0,y,-z));
	vertex_list.push_back(new Vertex(0,0,-z));

	vertex_list.push_back(new Vertex(0,0,z));
	vertex_list.push_back(new Vertex(x,0,-z));
	vertex_list.push_back(new Vertex(x,0,z));

	vertex_list.push_back(new Vertex(0,0,z));
	vertex_list.push_back(new Vertex(0,0,-z));
	vertex_list.push_back(new Vertex(x,0,-z));

	vertex_list.push_back(new Vertex(0,y,z));
	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(z,y,-z));

	vertex_list.push_back(new Vertex(0,y,z));
	vertex_list.push_back(new Vertex(x,y,-z));
	vertex_list.push_back(new Vertex(0,y,-z));

	return vertex_list;
}