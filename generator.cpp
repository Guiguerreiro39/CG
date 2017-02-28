#include <string.h>
#include <iostream>
#include <fstream>
#include "Plane.h"
#include "Box.h"
#include "Vertex.h"

using namespace std; 

void printFile(vector<Vertex*> v, string file_name){

	ofstream file (file_name);
	if(file.is_open()){
		// file << v.size() << endl; imprimir o número de vértices (por enqt não é necessário)
		for (vector<Vertex*>::iterator it = v.begin() ; it != v.end(); ++it)
    		file << (*it)->print() << endl;
		file.close();
	}
	else cout << "Unable to open file." << endl;
}

int main(int argc, char** argv){

	vector<Vertex*> v;

	if(!strcmp(argv[1],"plane") && argc == 4)
		v = createPlane(atof(argv[2]));

	else if(!strcmp(argv[1],"box") && argc == 6)
		v = createBox(atof(argv[2]),atof(argv[3]),atof(argv[4]));
	
	else cout << "Invalid input." << endl; 
	printFile(v,argv[argc-1]);

	return 0;
}