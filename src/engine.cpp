#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/tinyxml2.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "headers/Parser.h"

using namespace std;
using namespace tinyxml2;

// Geral
Group* scene;

// Mouse and Keyboard interaction
float angleX = 1.0, angleY = 1.0;
float camX = 5.0, camY = 5.0, camZ = 5.0;
float raio = 10.0f;
float xp = 40, yp = 10, zp = 100, xr = 0, yr = 0, angle = 0.0;
int linha = GL_LINE;

// Frames Per Second
int timebase = 0, frame = 0;

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
	cout << "| - w: Move your position forward                                |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - s: Move your position back                                   |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - a: Move your position to the left                            |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - d: Move your position to the right                           |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - ↑ : Rotate your view up                                      |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - ↓ : Rotate your view down                                    |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - ← : Rotate your view to the left                             |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - → : Rotate your view to the right                            |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - r : Reset the camera to the initial position                 |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   FORMAT:                                                      |" << endl;													        
	cout << "| - p: Change the figure format into points                      |" << endl;														    
	cout << "|                                                                |" << endl;
	cout << "| - l: Change the figure format into lines                       |" << endl;
	cout << "|                                                                |" << endl;	
	cout << "| - o: Fill up the figure                                        |" << endl;														
	cout << "#________________________________________________________________#" << endl;        
}

void displayFPS() {
	int time;
	char title[20];

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		float fps = frame * 1000.0/(time - timebase);
		timebase = time;
		frame = 0;
		sprintf(title,"Engine  |  %.2f FPS",fps);
		glutSetWindowTitle(title);
  }
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the viewport to be the entire window
	glViewport(0, 0,(GLsizei)w, (GLsizei)h);
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set perspective
	gluPerspective(45.0f ,ratio, 0.1f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
} 

void renderGroup(Group* group){

	float x,y,z;
	float te, gt, r, gr;
	float res[3];
	float deriv[3];

	glPushMatrix();

	Rotation* rotation=group->getRotation();
	if(rotation)
		rotation->apply();

	Translation* translation=group->getTranslation();
	if(translation)
		translation->apply();

	Scale* scale=group->getScale();
	if(scale)
		scale->apply();
		glScalef(scale->getX(),scale->getY(),scale->getZ());

	vector<Shape*> shape_list = group->getShapes();
	for(vector<Shape*>::iterator shape_it = shape_list.begin(); shape_it != shape_list.end(); ++shape_it){
		Shape* shape = (*shape_it);
		shape->draw();
	}
	glColor3f(255,255,255);

	vector<Group*>  childs = group->getChilds();
	for(vector<Group*>::iterator group_it = childs.begin(); group_it != childs.end(); ++group_it) 
		renderGroup(*group_it);

	glPopMatrix();
}


void renderScene(void) {

	int i = 0;

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	
	// put drawing instructions here
	glPolygonMode(GL_FRONT_AND_BACK,linha);

	glTranslatef(0.0f, 0.0f, -raio);
	glRotatef(xr,1.0,0.0,0.0);

	glRotatef(yr,0.0,1.0,0.0); 
	glTranslated(-xp,-yp,-zp);

	renderGroup(scene);
	displayFPS();

	// End of frame
	glutSwapBuffers();
	angle++;
} 

void keyboard (unsigned char key, int x, int y) {
	
	float xrotrad, yrotrad;

	switch(key){
    	case 'w':	yrotrad = (yr / 180 * M_PI);
    				xrotrad = (xr / 180 * M_PI); 
    				xp += float(sin(yrotrad)) * 2;
    				zp -= float(cos(yrotrad)) * 2;
    				yp -= float(sin(xrotrad)) * 2;
    				break;
    	case 's':	yrotrad = (yr / 180 * M_PI);
    				xrotrad = (xr / 180 * M_PI); 
    				xp -= float(sin(yrotrad)) * 2;
    				zp += float(cos(yrotrad)) * 2;
    				yp += float(sin(xrotrad)) * 2;
    				break;
    	case 'd':	yrotrad = (yr / 180 * M_PI);
    				xp += float(cos(yrotrad)) * 2;
    				zp += float(sin(yrotrad)) * 2;
    				break;
    	case 'a':	yrotrad = (yr / 180 * M_PI);
    				xp -= float(cos(yrotrad)) * 2;
    				zp -= float(sin(yrotrad)) * 2;
    				break;
    	case 'p':	linha = GL_POINT;
    				break;
    	case 'l':	linha = GL_LINE;
    				break;
    	case 'o':	linha = GL_FILL;
    				break;
    }
}

void keyboardArrows (int key_code, int x , int y){
	switch(key_code){
		case GLUT_KEY_UP: 	xr+=3;
						 	break;
		case GLUT_KEY_DOWN:	xr-=3;
							break;
		case GLUT_KEY_LEFT: yr-=3;
							break;
		case GLUT_KEY_RIGHT:yr+=3; 
							break;
	}
}

void initGroup(Group* group){

	vector<Shape*> shape_list = group->getShapes();
	for(vector<Shape*>::iterator shape_it = shape_list.begin(); shape_it != shape_list.end(); ++shape_it){
		Shape* shape = (*shape_it);
		shape->prepare();
	}

	vector<Group*> childs = group->getChilds();
	for(vector<Group*>::iterator group_it = childs.begin(); group_it != childs.end(); ++group_it) 
		initGroup(*group_it);
}

void initGL(){

	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// recursive init
	initGroup(scene);
}

int main(int argc, char** argv){

	vector<string> file_list;
	string line;
	int r;

	if(argc < 2){
		cout << "Invalid input. Use -h if you need some help." << endl;
		return 0;
	}
	else if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"-help")){
		printHelp();
		return 0;
	}
	else
		scene = parseXML(argv[1]);
 
 	if(scene){
		// put GLUT init here
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(800,800);
		glutCreateWindow("CG_Trabalho");

		// put callback registration here
		glutDisplayFunc(renderScene);
		glutIdleFunc(renderScene);
		glutReshapeFunc(changeSize);

		// put here the registration of the keyboard callbacks
		glutKeyboardFunc(keyboard);
		glutSpecialFunc(keyboardArrows);

		initGL();

		// enter GLUT's main loop
		glutMainLoop(); 
	}

	return 0;
}



