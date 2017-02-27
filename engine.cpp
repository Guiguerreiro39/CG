#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Vertex.h"

using namespace std;

vector<Vertex*> readFile(char* file_name){

	vector<Vertex*> vertex_list;
	vector<string> tokens;
	string buf;
	string line;
	int index = 0;

	ifstream file (file_name);
	if(file.is_open()){
		while(getline(file,line)){ // percorrer as linhas do ficheiro
			stringstream ss(line); 
			while(ss >> buf) tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			vertex_list.push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incfementar o índice
		}
		file.close();
	}
	else cout << "Unable to open file." << endl;
	return vertex_list;

}

int main(int argc, char** argv){

	vector<Vertex*> v;
	string line;

	if(argc != 2) cout << "Invalid input." << endl;
	else{
		v = readFile(argv[1]);
		for (vector<Vertex*>::iterator it = v.begin() ; it != v.end(); ++it)
    		cout << (*it)->print() << endl;
	} 
	return 0;

}

