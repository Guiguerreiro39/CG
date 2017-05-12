#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <string>
#include "Point.h"
#include <GL/glut.h>

using namespace std;

class Camera{

	int xOri;
	int yOri;
	float alpha, beta;
	Point* cameraPosition;
	Point* cameraFront;
	Point* cameraTilt;
	float cameraSpeed;
	bool specialKeys[128];
	bool normalKeys[256];

	public:
		Camera();
		void move();
		void mousePress(int button, int state, int x, int y);
		void mouseMotion(int, int);
		void specialKey(int, bool);
		void normalKey(unsigned char, bool);
		Point* getPosition();
		Point* getFront();
		Point* getTilt();
		Point* getFocus();
		float getCameraSpeed();
		bool* getSpecialKeys();
		bool* getNormalKeys();
		void setPosition(Point*);
		void setFront(Point*);
		void setTilt(Point*);
		void setCameraSpeed(float);
};

#endif