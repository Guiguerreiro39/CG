#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "headers/Parser.h"
#include "headers/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

// Geral
Group* scene;

// Mouse and Keyboard interaction
float angleX = 1.0, angleY = 1.0;
float camX = 5.0, camY = 5.0, camZ = 5.0;
float raio = 10.0f;
float xp = 0, yp = 5, zp = 20, xr = 0, yr = 0, angle = 0.0;
int linha = GL_LINE;

// mouse motion
//int startX, startY, tracking = 0;
//int alpha = 0, beta = 0, r = 5;

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
	//gluPerspective(45.0f ,ratio, 0.1f ,1000.0f);
	gluPerspective(45,ratio,1,1000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
} 

void renderGroup(Group* group){

	glPushMatrix();

	vector<Light*> lights = group->getLights();
	for(vector<Light*>::iterator light_it = lights.begin(); light_it != lights.end(); ++light_it){
		// Light
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		(*light_it)->draw();
	}

	vector<Operation*> operations = group->getOperations();
	for(vector<Operation*>::iterator operation_it = operations.begin(); operation_it != operations.end(); ++operation_it)
		(*operation_it)->apply();

	vector<Shape*> shape_list = group->getShapes();
	for(vector<Shape*>::iterator shape_it = shape_list.begin(); shape_it != shape_list.end(); ++shape_it)
		(*shape_it)->draw();
	
	vector<Group*> childs = group->getChilds();
	for(vector<Group*>::iterator group_it = childs.begin(); group_it != childs.end(); ++group_it) 
		renderGroup(*group_it);

	glPopMatrix();
} 


void renderScene(void) {

	// clear buffers
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	
	// put drawing instructions here
	glPolygonMode(GL_FRONT_AND_BACK,linha);
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	glTranslatef(0.0f, 0.0f, -raio);
	glRotatef(xr,1.0,0.0,0.0);

	glRotatef(yr,0.0,1.0,0.0); 
	glTranslated(-xp,-yp,-zp);

	glColor3f(255,255,255);

	renderGroup(scene);

	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0,0,0);
		glVertex3f(0,10,0);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0,0,0);
		glVertex3f(0,0,10);
	glEnd();

	glColor3f(0.3,0.1,0.6);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0,0,0);
		glVertex3f(10,0,0);
	glEnd();

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

void initGL(){

	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	// Textures
	glEnable(GL_TEXTURE_2D);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Refresh normals after scale
	glEnable(GL_NORMALIZE);

} 

int main(int argc, char** argv){

	// put GLUT init here
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG_Trabalho");
	ilInit(); 

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



