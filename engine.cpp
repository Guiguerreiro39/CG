#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <tinyxml2.h>
#include "Vertex.h"
#include <stdio.h>

using namespace std;
using namespace tinyxml2;

//vector<Vertex*> global_vertex_list;

vector<Vertex*> readFile(string file_name){

	vector<Vertex*> vertex_list;
	vector<string> tokens;
	string buf;
	string line;
	int index = 0;

	ifstream file (file_name);
	if(file.is_open()){
		while(getline(file,line)){ // percorrer as linhas do ficheiro
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			vertex_list.push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}
		file.close();
	}
	else cout << "Unable to open file." << endl;
	return vertex_list;
}

vector<string> lookupFiles(char* file_name){

	vector<string> file_list;
	XMLDocument doc;
	XMLElement* element;
	string file;

	doc.LoadFile(file_name);
	element = doc.FirstChildElement("scene")->FirstChildElement("model");
	for(;element;element=element->NextSiblingElement()){
		if(!strcmp(element->Name(),"model")){
			file = element->Attribute("file");
			file_list.push_back(file);
			cout << file << endl;
		}
	}
	return file_list;

}

int main(int argc, char** argv){

	vector<string> file_list;
	string line;

	if(argc != 2) cout << "Invalid input." << endl;
	else{

		file_list = lookupFiles(argv[1]);
		for(vector<string>::const_iterator i = file_list.begin(); i != file_list.end(); ++i){
			vector<Vertex*> aux = readFile(*i);
		}

	} 
	return 0;
}

