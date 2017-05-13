#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "headers/Parser.h"
#include "headers/tinyxml2.h"
#include "headers/Camera.h"

using namespace std;
using namespace tinyxml2;

// Geral
Group* scene;
Camera* camera;

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

	// Camera instructions
	Point* position = camera->getPosition();
	Point* focus = camera->getFocus();
	Point* tilt = camera->getTilt();

	gluLookAt( position->getX(), position->getY(), position->getZ(),
               focus->getX(), focus->getY(), focus->getZ(),
               tilt->getX(),  tilt->getY(),  tilt->getZ() );
	camera->move(); 

	glColor3f(255,255,255);

	renderGroup(scene);

	displayFPS();

	// End of frame
	glutSwapBuffers();
} 

void keyboard(unsigned char key_code, int x, int y){

	switch(key_code){
    	case 'p':	linha = GL_POINT;
    				break;
    	case 'l':	linha = GL_LINE;
    				break;
    	case 'o':	linha = GL_FILL;
    				break;
    	case '+': 	camera->incSpeed();
					break;
		case '-': 	camera->decSpeed();
					break;
    	default :	camera->normalKey(key_code, true);
					glutPostRedisplay();
	}
}

void upkeyboard(unsigned char key_code, int x, int y){
	camera->normalKey(key_code, false);
	glutPostRedisplay();
}
void specialkeyboard(int key_code, int x, int y){
	camera->specialKey(key_code, true);
	glutPostRedisplay();
}

void upspecialkeyboard(int key_code, int x, int y){
	camera->specialKey(key_code, false);
	glutPostRedisplay();
} 

void mousePress(int button, int state, int x, int y) {
	camera->mousePress(button, state, x, y);
} 

void mouseMotion(int xx, int yy){
	camera->mouseMotion(xx, yy);
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
	camera = new Camera();

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
		glutKeyboardUpFunc(upkeyboard);
		glutSpecialFunc(specialkeyboard);
		glutSpecialUpFunc(upspecialkeyboard);
		glutMotionFunc(mouseMotion); 
		glutMouseFunc(mousePress);

		initGL();

		// enter GLUT's main loop
		glutMainLoop(); 
	}

	return 0;
}



