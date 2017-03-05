#include <string.h>
#include <iostream>
#include <fstream>
#include "headers/Plane.h"
#include "headers/Box.h"
#include "headers/Sphere.h"
#include "headers/Cone.h"
#include "headers/Vertex.h"
#include "headers/Cylinder.h"

using namespace std; 

void printFile(vector<Vertex*> v, string file_name){

	system("mkdir -p ../files/ ");
	string file_dir = "../files/" + file_name;

	ofstream file (file_dir);
	if(file.is_open()){
		for (vector<Vertex*>::iterator it = v.begin() ; it != v.end(); ++it)
			file << (*it)->print() << endl;
		file.close();
	}
	else cout << "Unable to open file." << endl;
}

void printHelp(){
	cout << " HELP MENU " << endl;
}

int main(int argc, char** argv){

	vector<Vertex*> v;

	if(!strcmp(argv[1],"plane") && argc == 4)
		v = createPlane(atof(argv[2]));

	else if(!strcmp(argv[1],"box") && argc == 7)
		v = createBox(atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]));

	else if(!strcmp(argv[1],"sphere") && argc == 6)
		v = createSphere(atof(argv[2]),atof(argv[3]),atof(argv[4]));

	else if(!strcmp(argv[1],"cone") && argc == 7)
		v = createCone(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));

	else if(!strcmp(argv[1],"cylinder") && argc == 7)
		v = createCylinder(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));

	else if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"-help"))
		printHelp();	

	else cout << "Invalid input. Use -h if you need some help." << endl; 

	if(v.size()) printFile(v,argv[argc-1]);

	return 0;
}
