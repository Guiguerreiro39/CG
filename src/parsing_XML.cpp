#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/tinyxml2.h"
#include "headers/Group.h"

using namespace std;
using namespace tinyxml2;

Group* hereditaryChild(Group* father, vector<Group*>* group_list){

	Group* son = new Group(group_list->size());
	father->addChild(son);

	son->setTranslation(new Translation(0,0,0));
	son->setRotation(new Rotation(0,0,0,0));
	son->setScale(new Scale(0,0,0));

	if(father->getTranslation())
		son->setTranslation(father->getTranslation()->clone());
	
	if(father->getRotation())
		son->setRotation(father->getRotation()->clone());

	if(father->getScale())
		son->setScale(father->getScale()->clone());

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

vector<string> exploreModels(XMLElement* element){

	vector<string> models_list;

	element = element->FirstChildElement();
	for(;element;element=element->NextSiblingElement())
		if(!strcmp(element->Name(),"model"))
			models_list.push_back(element->Attribute("file"));
		
	return models_list;
}

void exploreElement(XMLElement* element, Group* group, vector<Group*>* group_list){

	// NOTA: Cada grupo só pode ter um grupo MODELS e um
	// grupo para cada transformação, tenho de verificar
	// essa porra!!!!!!!!!!!!!

	/**for(int i=0; i<group_list.size(); i++){
		group_list[i]->print();
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; **/

	XMLElement* initial = element;


	if(!strcmp(element->Name(),"translate")){
		updateTranslation(element,group);
	}

	else if(!strcmp(element->Name(),"rotate")){
		updateRotation(element,group);
	}

	else if(!strcmp(element->Name(),"scale")){
		updateScale(element,group);
	}

	else if(!strcmp(element->Name(),"models")){
		vector<string> models_list = exploreModels(element);
		group->setShapes(models_list);
	}

	// Percorrer os filhos
	else if(!strcmp(element->Name(),"group")){	
		Group* child_group = hereditaryChild(group,group_list);
		group_list->push_back(child_group);
		element=element->FirstChildElement();
		if(element){
			exploreElement(element,child_group,group_list);		
		}
	}

	// Percorrer os irmãos
	initial=initial->NextSiblingElement();
	if(initial){
		//Group* new_group = new Group(n_groups++);
		exploreElement(initial,group,group_list);
		//group_list.push_back(new_group);
	} 
}

vector<Group*> parseXML(char* file_name){

	XMLDocument doc;
	XMLElement* element;
	XMLError error;
	vector<Group*> group_list;

	Group* group = new Group(group_list.size()); // Este é o grupo 0 -> corresponde à 'Scene'.
	group_list.push_back(group);

	error = doc.LoadFile(file_name);
	if(error == 0){
		element = doc.FirstChildElement("scene")->FirstChildElement("group");
		exploreElement(element,group,&group_list);
	}
	else
		cout << "Could not load XML file: " << file_name << "." << endl;


	return group_list;

}

int main(int argc, char** argv){

	vector<Group*> group_list = parseXML(argv[1]);

	for(int i=0; i<group_list.size(); i++){
		group_list[i]->print();
	}

	return 0;
}