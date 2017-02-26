#include <string.h>
#include <iostream>
#include <fstream>
#include "Plane.h"

using namespace std; 

void printFile(vector<Vertex*> v, string file_name){

	ofstream file (file_name);
	if(file.is_open()){
		file << "Hello World.\n";
		file << "Dinis Peixoto.";
		file.close();
	}
	else cout << "Unable to open file.\n";
}

int main(int argc, char** argv){

	vector<Vertex*> v;

	if(!strcmp(argv[1],"plane")){
		v = createPlane(atof(argv[2]));
		printFile(v,argv[3]);
	}
	else cout << "Invalid input.\n"; 

	return 0;
}