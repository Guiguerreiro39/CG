#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "headers/Figures.h"
#include "headers/Patch.h"

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
	else cout << "Unable to open file: " << file_name << "." << endl;
}

string getLineNumber(string file_name, int n_line){

	string line;
	
	ifstream file;
	file.open(file_name);

	if(file.is_open()){
		for(int i=0; i < n_line; i++)
			getline(file,line);
		file.close();
	}
	else cout << "Unable to open patch file: " << file_name << "." << endl;
 

	return line;
}

void parsePatchFile(int tessellation, string file_name, string output_file){

	string line, token, line_cpy, n_line;
	int n_patches, n_points, position;
	int index;
	int contador = 0; // retirar
	float value;
	float vertex_coords[3];

	vector<Patch*> patches_list;

	ifstream file;
	file.open(file_name);

	if(file.is_open()){
		
		// Number of patches
		getline(file,line);
		n_patches = atoi(line.c_str());

		// Parsing indexes
		for(int i=0; i<n_patches; i++){

			getline(file,line);

			Patch* patch = new Patch();
			patches_list.push_back(patch);

			for(int j=0; j<16; j++){

				position = line.find(",");
				token = line.substr(0, position);
				index = atoi(token.c_str());
				line.erase(0, position + 1);

				n_line = getLineNumber(file_name, n_patches + 3 + index);
				line_cpy = n_line;

				for(int j=0; j<3; j++){
						position = n_line.find(",");
						token = n_line.substr(0, position);
						vertex_coords[j] = atof(token.c_str());
						n_line.erase(0, position + 1);
				}

				n_line = line_cpy;
				patch->addVertex(new Vertex(vertex_coords[0],vertex_coords[1],vertex_coords[2]));
			}
		}

		printFile(renderBezierPatch(tessellation,patches_list),output_file);

		file.close();
	}

	else cout << "Unable to open patch file: " << file_name << "." << endl;
	
}

void printHelp(){
	cout << "#_____________________________ HELP _____________________________# " << endl;
	cout << "|                                                                |" << endl;
	cout << "|   Usage: ./generator {COMMAND} ... {OUTPUT FILE}               |" << endl;
	cout << "|                      [-h]                                      |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   COMMANDS:                                                    |" << endl;
	cout << "| - plane [SIZE]                                                 |" << endl;
	cout << "|      Creates a square in the XZ plane, centred in the origin.  |" << endl; 
	cout << "|                                                                |" << endl;
	cout << "| - box [SIZE X] [SIZE Y] [SIZE Z] [DIVISIONS]                   |" << endl;
	cout << "|      Creates a box with the dimensions and divisions specified.|" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - sphere [RADIUS] [SLICE] [STACK]                              |" << endl;
	cout << "|      Creates a sphere with the radius, number of slices and    |" << endl;
	cout << "|      stacks given.                                             |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - cone [RADIUS] [HEIGHT] [SLICE] [STACK]                       |" << endl;
	cout << "|      Creates a cone with the radius, height, number of slices  |" << endl;
	cout << "|      and stacks given.                                         |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - torus [INNER RADIUS] [OUTER RADIUS] [SIDES] [RINGS]          |" << endl;
	cout << "|      Creates a torus with the inner and outer radius, sides    |" << endl;
	cout << "|      and rings given.                                          |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - patch [TESSELLATION LEVEL] [INPUT FILE]                      |" << endl;
	cout << "|      Creates a new type of model based on Bezier patches.      |" << endl;
	cout << "|                                                                |" << endl;													        
	cout << "|   OUTPUT FILE:                                                 |" << endl;														    
	cout << "| In the file section you can specify any file in which you wish |" << endl;
	cout << "| to save the coordinates generated with the previous commands.  |" << endl;
	cout << "|                                                                |" << endl;															
	cout << "#________________________________________________________________#" << endl;        
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

	else if(!strcmp(argv[1],"torus") && argc == 7)
		v = createTorus(atof(argv[2]),atof(argv[3]),atoi(argv[4]),atoi(argv[5]));

	else if(!strcmp(argv[1],"patch") && argc == 5){
		parsePatchFile(atoi(argv[2]),argv[3],argv[4]);
	}

	else if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"-help"))
		printHelp();	

	else cout << "Invalid input. Use -h if you need some help." << endl; 

	if(v.size()) printFile(v,argv[argc-1]);

	return 0;
}
