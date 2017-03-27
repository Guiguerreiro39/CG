#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/tinyxml2.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>

#include "headers/Parser.h"

using namespace std;
using namespace tinyxml2;

vector<Group*> group_list;

float angleX = 1.0, angleY = 1.0;
int linha = GL_LINE;

void printHelp(){
	cout << "#_____________________________ HELP _____________________________#" << endl;
	cout << "|                                                                |" << endl;
	cout << "| Usage: ./engine {XML FILE}                                     |" << endl;
	cout << "|                 [-h]                                           |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   FILE:                                                        |" << endl;
	cout << "| Specify a path to an XML file in which the information about   |" << endl;
	cout << "| the models you wish to create are specified                    |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   MOVE:                                                        |" << endl;
	cout << "| - a: Move the window to the right (X positive direction)       |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - d: Move the window to the left (X negative direction)        |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - w: Move the window up (Y positive direction)                 |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - s: Move the window down (Y negative direction)               |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   FORMAT:                                                      |" << endl;													        
	cout << "| - p: Change the figure format into points                      |" << endl;														    
	cout << "|                                                                |" << endl;
	cout << "| - l: Change the figure format into lines                       |" << endl;
	cout << "|                                                                |" << endl;	
	cout << "| - o: Fill up the figure                                        |" << endl;														
	cout << "#________________________________________________________________#" << endl;        
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

	int i = 0;
	float x,y,z;

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	// put drawing instructions here
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, linha);
	
	glRotatef(angleX,0,1,0);
	glRotatef(angleY,0,0,1);

	glColor3f(255,255,255);

	for(vector<Group*>::iterator group_it = group_list.begin(); group_it != group_list.end(); ++group_it){
		glPushMatrix();
		Translation* translation = (*group_it)->getTranslation();
		Rotation* rotation = (*group_it)->getRotation();
		Scale* scale = (*group_it)->getScale();

		if(translation)
			glTranslatef(translation->getX(),translation->getY(),translation->getZ());
		if(rotation)
			glRotatef(rotation->getAngle(),rotation->getX(),rotation->getY(),rotation->getZ());
		if(scale)
			glScalef(scale->getX(),scale->getY(),scale->getZ());

		vector<Shape*> shape_list = (*group_it)->getShapes();

		for(vector<Shape*>::iterator shape_it = shape_list.begin(); shape_it != shape_list.end(); ++shape_it){
			glBegin(GL_TRIANGLES);
			Shape* shape = (*shape_it);
			
			vector<Vertex*> vertex_list = shape->getVertexList();

			for(vector<Vertex*>::const_iterator vertex_it = vertex_list.begin(); vertex_it != vertex_list.end(); ++vertex_it){					
				x = (*vertex_it)->getX();
				y = (*vertex_it)->getY();
				z = (*vertex_it)->getZ();
				glVertex3f(x,y,z);
			}

			glEnd();
		}
		glPopMatrix();
	}
	
	// End of frame
	glutSwapBuffers();
} 

void keyboard (unsigned char key, int x, int y){
	
	switch(key){
		case 'a': angleX+=3.0;
				  break;
		case 'd': angleX-=3.0;
				  break;
		case 'w': angleY+=3.0;
				  break;
		case 's': angleY-=3.0;
				  break;
		case 'p': linha = GL_POINT;
				  break;
		case 'l': linha = GL_LINE; 
				  break;
		case 'o': linha = GL_FILL;
				  break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv){

	vector<string> file_list;
	string line;
	int r;


	if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"-help")){
		printHelp();
		return 0;
	}
	else if(argc != 2){
		cout << "Invalid input. Use -h if you need some help." << endl;
		return 0;
	}
	else{

		group_list = parseXML(argv[1]);
		group_list.erase(group_list.begin());

		for(vector<Group*>::iterator group_it = group_list.begin(); group_it != group_list.end(); ++group_it){

			cout << "################# Grupo " << (*group_it)->getID() << " #################" << endl;

			if((*group_it)->getTranslation()){
				Translation* translation=(*group_it)->getTranslation();
				cout << "Translation: " << translation->getX() << " | " << translation->getY() << " | " << translation->getZ()  << endl;
			}

			if((*group_it)->getRotation()){
				Rotation* rotation=(*group_it)->getRotation();
				cout << "Rotation: " << rotation->getAngle() << " | " << rotation->getX() << " | " << rotation->getY() << " | " << rotation->getZ()  << endl;
			}
			
			if((*group_it)->getScale()){
				Scale* scale=(*group_it)->getScale();
				cout << "Scale: " << scale->getX() << " | " << scale->getY() << " | " << scale->getZ()  << endl;
			}

			cout << "Tamanho: " << (*group_it)->getShapes().size() << endl;
			cout << "Models: ";
			for(vector<Shape*>::iterator it_lista = (*group_it)->getShapes().begin(); it_lista != (*group_it)->getShapes().end(); ++it_lista){
					cout << (*it_lista)->getName() << "; ";
			}
			cout << endl;

			cout << "Childs: ";
			for(vector<Group*>::iterator it = (*group_it)->getChilds().begin(); it != (*group_it)->getChilds().end(); ++it){
				cout << (*it)->getID() << "; ";
			}
			cout << endl;

			cout << "#################################################" <<endl;
		}	

		//return 1;

	} 

	// put GLUT init here
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG_Trabalho");

	// put callback registration here
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// put here the registration of the keyboard callbacks
	glutKeyboardFunc(keyboard);
	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main loop
	glutMainLoop();

	return 0;
}

