#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "tinyxml2.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>

#include "Vertex.h"
#include "Shape.h"

using namespace std;
using namespace tinyxml2;


vector<Shape*> shapes_list;
int total_shapes = 0;


vector<Vertex*> readFile(string file_name){

	vector<Vertex*> vertex_list;
	vector<string> tokens;
	string buf;
	string line;
	int index = 0;

	ifstream file (file_name);
	if(file.is_open()){
		while(getline(file,line)){ // percorrer as linhas do ficheiro
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			vertex_list.push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}
		file.close();
	}
	else cout << "Unable to open file." << endl;
	return vertex_list;
}

vector<string> lookupFiles(char* file_name){

	vector<string> file_list;
	XMLDocument doc;
	XMLElement* element;
	string file;

	doc.LoadFile(file_name);
	element = doc.FirstChildElement("scene")->FirstChildElement("model");
	for(;element;element=element->NextSiblingElement()){
		if(!strcmp(element->Name(),"model")){
			file = element->Attribute("file");
			file_list.push_back(file);
			cout << file << endl;
		}
	}
	return file_list;

}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	int i = 0,x,y,z;

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	// put drawing instructions here
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glColor3f(0.33,0.33,0.33);

	glBegin(GL_TRIANGLES);
	for (vector<Shape*>::iterator shape_it = shapes_list.begin(); shape_it != shapes_list.end(); ++shape_it)
		for(vector<Vertex*>::iterator vertex_it = (*shape_it)->getVertexList().begin(); vertex_it != (*shape_it)->getVertexList().end(); ++vertex_it){
			x = ((*shape_it)->getVertexList())[i]->getX();
			y = ((*shape_it)->getVertexList())[i]->getY();
			z = ((*shape_it)->getVertexList())[i]->getZ();
			glVertex3f(x,y,z);
			i++;
		}
	glEnd();
	
	// End of frame
	glutSwapBuffers();
} 

int main(int argc, char** argv){

	vector<string> file_list;
	string line;
	int r;

	if(argc != 2){
		cout << "Invalid input." << endl;
		return 0;
	}
	else{

		file_list = lookupFiles(argv[1]);

		for(vector<string>::const_iterator i = file_list.begin(); i != file_list.end(); ++i){
			vector<Vertex*> aux = readFile(*i);
			shapes_list.push_back(new Shape(total_shapes,aux));
			total_shapes++;
		}
	} 

	/** int i = 0;
	for (vector<Shape*>::iterator shape_it = shapes_list.begin(); shape_it != shapes_list.end(); ++shape_it)
		for(vector<Vertex*>::iterator vertex_it = (*shape_it)->getVertexList().begin(); vertex_it != (*shape_it)->getVertexList().end(); ++vertex_it){
			cout << ((*shape_it)->getVertexList())[i]->print() << endl; 
			i++;
		} **/

	// put GLUT init here
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG_Trabalho");

	// put callback registration here
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main loop
	glutMainLoop();

	return 0;
}

