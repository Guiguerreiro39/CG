#include "Box.h"

vector<Vertex*> createBox(float cX, float cY, float cZ){

	vector<Vertex*> vertex_list;
	float x = cX/2;
	float y = cY/2;
	float z = cZ/2;
	
	vertex_list.push_back(new Vertex(x,-y,z));
	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(-x,-y,z));

	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(-x,y,z));
	vertex_list.push_back(new Vertex(-x,-y,z));

	vertex_list.push_back(new Vertex(x,-y,-z));
	vertex_list.push_back(new Vertex(-x,-y,-z));
	vertex_list.push_back(new Vertex(x,y,-z));

	vertex_list.push_back(new Vertex(x,y,-z));
	vertex_list.push_back(new Vertex(-x,-y,-z));
	vertex_list.push_back(new Vertex(-x,y,-z));

	vertex_list.push_back(new Vertex(x,-y,z));
	vertex_list.push_back(new Vertex(x,-y,-z));
	vertex_list.push_back(new Vertex(x,y,z));

	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(x,-y,-z));
	vertex_list.push_back(new Vertex(x,y,-z));

	vertex_list.push_back(new Vertex(-x,-y,z));
	vertex_list.push_back(new Vertex(-x,y,z));
	vertex_list.push_back(new Vertex(-x,-y,-z));

	vertex_list.push_back(new Vertex(-x,y,z));
	vertex_list.push_back(new Vertex(-x,y,-z));
	vertex_list.push_back(new Vertex(-x,-y,-z));

	vertex_list.push_back(new Vertex(-x,-y,z));
	vertex_list.push_back(new Vertex(x,-y,-z));
	vertex_list.push_back(new Vertex(x,-y,z));

	vertex_list.push_back(new Vertex(-x,-y,z));
	vertex_list.push_back(new Vertex(-x,-y,-z));
	vertex_list.push_back(new Vertex(x,-y,-z));

	vertex_list.push_back(new Vertex(-x,y,z));
	vertex_list.push_back(new Vertex(x,y,z));
	vertex_list.push_back(new Vertex(z,y,-z));

	vertex_list.push_back(new Vertex(-x,y,z));
	vertex_list.push_back(new Vertex(x,y,-z));
	vertex_list.push_back(new Vertex(-x,y,-z));

	return vertex_list;
}