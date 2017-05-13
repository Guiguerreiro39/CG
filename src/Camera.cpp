#include "headers/Camera.h"

Camera::Camera(){

	alpha = 0; 
	beta = 0;

	xOri = -1;
	yOri = -1;

	cameraPosition = new Point(0.0f, 0.0f, -50.0f);
	cameraFront = new Point(0.0f, 0.0f, -1.0f);
	cameraTilt = new Point(0.0f, 1.0f, 0.0f);
	cameraSpeed = 0.5;
	fill_n(specialKeys, 128, false);
	fill_n(normalKeys, 256, false);
}

void Camera::move(){

    if (normalKeys['w']){
		Point* p = new Point(*cameraFront);
		p->vector_scale(cameraSpeed);
		cameraPosition->incr(p);
    }

    if (normalKeys['s']){
		Point* p = new Point(*cameraFront);
		p->vector_scale(-cameraSpeed);
		cameraPosition->incr(p);
    }

    if (normalKeys['a']){
		float px = cameraPosition->getX();
		float py = cameraPosition->getY();
		float pz = cameraPosition->getZ();
		float rx = cameraFront->getX();
		float rz = cameraFront->getZ();
		px += rz*cameraSpeed;
		pz -= rx*cameraSpeed;

		cameraPosition = new Point(px, py, pz);
    }

    if (normalKeys['d']){
		float px = cameraPosition->getX();
		float py = cameraPosition->getY();
		float pz = cameraPosition->getZ();
		float rx = cameraFront->getX();
		float rz = cameraFront->getZ();
		px -= rz*cameraSpeed;
		pz += rx*cameraSpeed;

		cameraPosition = new Point(px, py, pz);
	}
}

// Motion while mouse button is pressed
void Camera::mouseMotion(int x, int y) {

	if (xOri >= 0) {
		int xDiff = x - xOri;
		int yDiff = y - yOri;
		alpha -= xDiff * 0.004f;
		beta -= yDiff * 0.004f;

		if (beta > (M_PI / 2) - 0.001) beta = (M_PI / 2) - 0.001;
		if (beta < -(M_PI / 2) + 0.001) beta = -(M_PI / 2) + 0.001;

		float x = cos(beta)*sin(alpha);
		float y = sin(beta);
		float z = cos(beta)*cos(alpha);
		cameraFront = new Point(x, y, z);
	}
	xOri = x;
	yOri = y;
} 

void Camera::mousePress(int button, int state, int x, int y){
	// Camera only moves while the left mouse button is pressed
	if (button == GLUT_LEFT_BUTTON) {
		// If the button is released, origin coordinates reset.
		if (state == GLUT_UP) {
			xOri = -1;
			yOri = -1;
		}
		// Else, button is pressed, origin coordinates are updated.
		else {
			xOri = x;
			yOri = y;
    	}
	}
}

void Camera::incSpeed(){
	cameraSpeed+=0.5;
}

void Camera::decSpeed(){
	if(cameraSpeed>0.5) cameraSpeed-=0.5;
}

void Camera::specialKey(int key, bool pressed){
    specialKeys[key] = pressed;
}
void Camera::normalKey(unsigned char key, bool pressed){
    normalKeys[key] = pressed;
}

Point* Camera::getPosition(){
	return cameraPosition;
}

Point* Camera::getFront(){
	return cameraFront;
}

Point* Camera::getTilt(){
	return cameraTilt;
}

Point* Camera::getFocus(){
	float x = cameraPosition->getX() + cameraFront->getX();
	float y = cameraPosition->getY() + cameraFront->getY();
	float z = cameraPosition->getZ() + cameraFront->getZ();
	return new Point(x, y, z);
}

float Camera::getCameraSpeed(){
	return cameraSpeed;
}

bool* Camera::getSpecialKeys(){
	return specialKeys;
}

bool* Camera::getNormalKeys(){
	return normalKeys;
}

void Camera::setPosition(Point* p){
	cameraPosition = p;
}

void Camera::setFront(Point* p){
	cameraFront = p;
}

void Camera::setTilt(Point* p){
	cameraTilt = p;
}

void Camera::setCameraSpeed(float v){
	cameraSpeed = v;
}
