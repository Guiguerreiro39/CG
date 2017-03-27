#include "headers/Parser.h"

int total_groups = 0;

Group* hereditaryChild(Group* father){

	Group* son = new Group(total_groups++);
	father->addChild(son);

	son->setTranslation(new Translation(0,0,0));
	son->setRotation(new Rotation(0,0,0,0));
	son->setScale(new Scale(1,1,1));
	son->setColour(new Colour(255,255,255));

	return son;
}

void updateTranslation(XMLElement* element, Group* group){

	Translation* translation = group->getTranslation();

	if(element->Attribute("X")) 
		translation->setX(stof(element->Attribute("X")));
	if(element->Attribute("Y")) 
		translation->setY(stof(element->Attribute("Y")));
	if(element->Attribute("Z")) 
		translation->setZ(stof(element->Attribute("Z")));
}

void updateRotation(XMLElement* element, Group* group){

	Rotation* rotation = group->getRotation();

	if(element->Attribute("angle"))
		rotation->setAngle(stof(element->Attribute("angle")));
	if(element->Attribute("X"))
		rotation->setX(stof(element->Attribute("X")));
	if(element->Attribute("Y"))
		rotation->setY(stof(element->Attribute("Y")));
	if(element->Attribute("Z"))
		rotation->setZ(stof(element->Attribute("Z")));
}

void updateScale(XMLElement* element, Group* group){

	Scale* scale = group->getScale();

	if(element->Attribute("X")) 
		scale->setX(stof(element->Attribute("X")));
	if(element->Attribute("Y")) 
		scale->setY(stof(element->Attribute("Y")));
	if(element->Attribute("Z")) 
		scale->setZ(stof(element->Attribute("Z")));
}

void updateColour(XMLElement* element, Group* group){

	Colour* colour = group->getColour();

	if(element->Attribute("R")) 
		colour->setR(stof(element->Attribute("R")));
	if(element->Attribute("G")) 
		colour->setG(stof(element->Attribute("G")));
	if(element->Attribute("B")) 
		colour->setB(stof(element->Attribute("B")));
}

vector<Shape*> exploreModels(XMLElement* element){

	vector<Shape*> models_list;
	string file_model;

	element = element->FirstChildElement();
	for(;element;element=element->NextSiblingElement())
		if(!strcmp(element->Name(),"model")){
			vector<Vertex*> vertex_list = readFile(element->Attribute("file"));
			if(vertex_list.size()){
				Shape* shape = new Shape(element->Attribute("file"),vertex_list);
				models_list.push_back(shape);
			}
			else return models_list;
			
		}
		
	return models_list;
}

void exploreElement(XMLElement* element, Group* group){

	// NOTA: Cada grupo só pode ter um grupo MODELS e um
	// grupo para cada transformação, tenho de verificar
	// essa porra!!!!!!!!!!!!!

	XMLElement* initial = element;


	if(!strcmp(element->Name(),"translate"))
		updateTranslation(element,group);
	
	else if(!strcmp(element->Name(),"rotate"))
		updateRotation(element,group);

	else if(!strcmp(element->Name(),"scale"))
		updateScale(element,group);

	else if(!strcmp(element->Name(),"colour"))
		updateColour(element,group);

	else if(!strcmp(element->Name(),"models")){
		vector<Shape*> models_list = exploreModels(element);
		if(models_list.size())
			group->setShapes(models_list);
	}

	// Percorrer os filhos
	else if(!strcmp(element->Name(),"group")){	
		Group* child_group = hereditaryChild(group);
		element=element->FirstChildElement();
		if(element){
			exploreElement(element,child_group);		
		}

	}

	// Percorrer os irmãos
	initial=initial->NextSiblingElement();
	if(initial)
		exploreElement(initial,group);
}

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

Group* parseXML(char* file_name){

	XMLDocument doc;
	XMLElement* element;
	XMLError error;

	Group* group = new Group(total_groups++); // Este é o grupo 0 -> corresponde à 'Scene'.
	group->setTranslation(new Translation(0,0,0));
	group->setRotation(new Rotation(0,0,0,0));
	group->setScale(new Scale(1,1,1));

	error = doc.LoadFile(file_name);
	if(error == 0){
		element = doc.FirstChildElement("scene")->FirstChildElement("group");
		exploreElement(element,group);
	}
	else
		cout << "Could not load XML file: " << file_name << "." << endl;


	return group;

}