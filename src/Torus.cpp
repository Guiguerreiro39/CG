#include "headers/Torus.h"

vector<Vertex*> createTorus(float radiusIn, float radiusOut, int sides, int rings){

	vector<Vertex*> vertex_list;

	float alfa,x,z,actualX,actualZ,actualY,nextX,nextXX,nextZ,nextY;
	float dimSide = (2*M_PI)/sides;
	float dimRing = (2*M_PI)/rings;

	for (int i = 0; i < rings; i++) {		
		beta = i * dimRing;
		
		actualZ = radiusOut * sin(beta);
		nextZ = radiusOut * sin(beta + dimRing);

		for (int j = 0; j < sides; j++) {
			alfa = j * dimSide;
			
			actualY = radiusIn * sin(alfa); 
			nextY = radiusIn * sin(alfa + dimSide);

			actualX = (radiusOut * cos(beta)) + (radiusIn * (1 - cos(alfa)));
			nextX = (radiusOut * cos(beta + dimRing)) + (radiusIn * (1 - cos(alfa)));
			nextXX = (radiusOut * cos(beta)) + (radiusIn * (1 - cos(alfa + dimSide)));
			nextXXX = (radiusOut * cos(beta + dimRing)) + (radiusIn * (1 - cos(alfa + dimSide)));

			glVertex3f(actualX,actualY,actualZ);
			glVertex3f(nextX,actualY,nextZ);
			glVertex3f(nextXX,nextY,actualZ);

			glVertex3f(nextXX,nextY,actualZ);
			glVertex3f(nextX,actualY,nextZ);
			glVertex3f(nextXXX,nextY,nextZ);
		}
	}
	return vertex_list;
}