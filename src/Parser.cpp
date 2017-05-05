#include "headers/Parser.h"

int total_groups = 0;

Group* hereditaryChild(Group* father){

	Group* son = new Group(total_groups++);
	father->addChild(son);

	son->setTranslation(new Translation(0,0,0,0));
	son->setRotation(new Rotation(0,0,0,0,0));
	son->setScale(new Scale(1,1,1));

	return son;
}

void updateTranslation(XMLElement* element, Group* group){

	Translation* translation = group->getTranslation();

	if(element->Attribute("time"))
		translation->setTime(stof(element->Attribute("time")));

	if(element->Attribute("X")) 
		translation->setX(stof(element->Attribute("X")));

	if(element->Attribute("Y")) 
		translation->setY(stof(element->Attribute("Y")));

	if(element->Attribute("Z")) 
		translation->setZ(stof(element->Attribute("Z")));

	XMLElement* point_element = element->FirstChildElement();

	for(;point_element;point_element=point_element->NextSiblingElement()){
		float x=0, y=0, z=0;

		if(point_element->Attribute("X")) 
			x = stof(point_element->Attribute("X"));
		if(point_element->Attribute("Y")) 
			y = stof(point_element->Attribute("Y"));
		if(point_element->Attribute("Z")) 
			z = stof(point_element->Attribute("Z"));

		Vertex* vertex = new Vertex(x,y,z);
		translation->addPoint(vertex);
	}
}

void updateRotation(XMLElement* element, Group* group){

	Rotation* rotation = group->getRotation();

	if(element->Attribute("angle"))
		rotation->setAngle(stof(element->Attribute("angle")));
	if(element->Attribute("time"))
		rotation->setTime(stof(element->Attribute("time")));
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

void updateColourComponent(XMLElement* element, Shape* shape){

	Colour* diffuse = new Colour(0.8, 0.8, 0.8);
	Colour* ambient = new Colour(0.2, 0.2, 0.2);
	Colour* specular = new Colour(0, 0, 0);
	Colour* emission = new Colour(0, 0, 0);
	float shininess = 0;

	// Diffuse
	if(element->Attribute("diffR"))
		diffuse->setR(stof(element->Attribute("diffR")));
	if(element->Attribute("diffG"))
		diffuse->setG(stof(element->Attribute("diffG")));
	if(element->Attribute("diffB"))
		diffuse->setB(stof(element->Attribute("diffB")));

	// Ambient
	if(element->Attribute("ambR"))
		ambient->setR(stof(element->Attribute("ambR")));
	if(element->Attribute("ambG"))
		ambient->setG(stof(element->Attribute("ambG")));
	if(element->Attribute("ambB"))
		ambient->setB(stof(element->Attribute("ambB")));

	// Specular
	if(element->Attribute("specR"))
		specular->setR(stof(element->Attribute("specR")));
	if(element->Attribute("specG"))
		specular->setG(stof(element->Attribute("specG")));
	if(element->Attribute("specB"))
		specular->setB(stof(element->Attribute("specB")));

	// Emission
	if(element->Attribute("emiR"))
		emission->setR(stof(element->Attribute("emiR")));
	if(element->Attribute("emiG"))
		emission->setG(stof(element->Attribute("emiG")));
	if(element->Attribute("emicB"))
		emission->setB(stof(element->Attribute("emiB")));

	// Shininess
	if(element->Attribute("shininess"))
		shininess = stof(element->Attribute("shininess"));

	Material* colour_component = new Material(diffuse, ambient, specular, emission, shininess);
	shape->setColourComponent(colour_component);
}

void exploreModels(XMLElement* element, Group* group){

	vector<Shape*> models_list;
	string file_model;

	element = element->FirstChildElement();
	for(;element;element=element->NextSiblingElement())
		if(!strcmp(element->Name(),"model")){

			vector<Vertex*> vertex_list; 
			vector<Vertex*> normal_list;
			vector<Vertex*> texture_list;
			readFile(element->Attribute("file"), &vertex_list, &normal_list, &texture_list);

			if(vertex_list.size()){

				Shape* shape = new Shape(element->Attribute("file"), vertex_list, normal_list, texture_list);
				updateColourComponent(element, shape);
				models_list.push_back(shape);
			}
		}
		
	if(models_list.size())
		group->setShapes(models_list);
}

void exploreElement(XMLElement* element, Group* group){

	XMLElement* initial = element;


	if(!strcmp(element->Name(),"translate"))
		updateTranslation(element,group);
	
	else if(!strcmp(element->Name(),"rotate"))
		updateRotation(element,group);

	else if(!strcmp(element->Name(),"scale"))
		updateScale(element,group);

	/** else if(!strcmp(element->Name(),"colour"))
		updateColour(element,group); **/

	else if(!strcmp(element->Name(),"models"))
		exploreModels(element, group);
	
	else if(!strcmp(element->Name(),"lights")){
		// trabalhar com luzes
	}

	// Percorrer os filhos
	else if(!strcmp(element->Name(),"group")){	
		Group* child_group = hereditaryChild(group);
		element=element->FirstChildElement();
		if(element)
			exploreElement(element,child_group);		
	}

	// Percorrer os irmãos
	initial=initial->NextSiblingElement();
	if(initial)
		exploreElement(initial,group);

}

void readFile(string file_name, vector<Vertex*>* vertex_list, vector<Vertex*>* normal_list, vector<Vertex*>* texture_list){

	vector<string> tokens;
	string buf;
	string line;
	int index;

	ifstream file (file_name);
	if(file.is_open()){

		index = 0;
		int n_vertex = getline(file, line);
		for(int i=0; i < n_vertex; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			vertex_list->push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}

		index = 0;
		int n_normal = getline(file, line);
		for(int i=0; i < n_normal; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			normal_list->push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}
		
		index = 0;
		int n_texture = getline(file, line);
		for(int i=0; i < n_texture; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			texture_list->push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}

		file.close();
	}
	else cout << "Unable to open file: " << file_name << "." << endl;
}

Group* parseXML(char* file_name){

	XMLDocument doc;
	XMLElement* element;
	Group* group;
	XMLError error;

	error = doc.LoadFile(file_name);
	if(error == 0){
		group = new Group(total_groups++); // Este é o grupo 0 -> corresponde à 'Scene'.
		group->setTranslation(new Translation(0,0,0,0));
		group->setRotation(new Rotation(0,0,0,0,0));
		group->setScale(new Scale(1,1,1));

		element = doc.FirstChildElement("scene")->FirstChildElement("group");
		exploreElement(element,group);
	}
	else
		cout << "Could not load XML file: " << file_name << "." << endl;

	return group;
}