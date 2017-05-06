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

		Point* point = new Point(x,y,z);
		translation->addPoint(point);
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
	if(element->Attribute("diffX"))
		diffuse->setR(stof(element->Attribute("diffX")));
	if(element->Attribute("diffY"))
		diffuse->setG(stof(element->Attribute("diffY")));
	if(element->Attribute("diffZ"))
		diffuse->setB(stof(element->Attribute("diffZ")));

	// Ambient
	if(element->Attribute("ambX"))
		ambient->setR(stof(element->Attribute("ambX")));
	if(element->Attribute("ambY"))
		ambient->setG(stof(element->Attribute("ambY")));
	if(element->Attribute("ambZ"))
		ambient->setB(stof(element->Attribute("ambZ")));

	// Specular
	if(element->Attribute("specX"))
		specular->setR(stof(element->Attribute("specX")));
	if(element->Attribute("specY"))
		specular->setG(stof(element->Attribute("specY")));
	if(element->Attribute("specZ"))
		specular->setB(stof(element->Attribute("specZ")));

	// Emission
	if(element->Attribute("emiX"))
		emission->setR(stof(element->Attribute("emiX")));
	if(element->Attribute("emiY"))
		emission->setG(stof(element->Attribute("emiY")));
	if(element->Attribute("emiZ"))
		emission->setB(stof(element->Attribute("emiZ")));

	// Shininess
	if(element->Attribute("shini"))
		shininess = stof(element->Attribute("shini"));

	Material* colour_component = new Material(diffuse, ambient, specular, emission, shininess);
	shape->setColourComponent(colour_component);
}

void updateLights(XMLElement* element, Group* group){

	vector<Light*> lights_list;
	bool isPoint;
	Light* light;
	float x=0, y=0, z=0;

	element = element->FirstChildElement();
	for(;element; element=element->NextSiblingElement())
		if(!strcmp(element->Name(),"light")){
			if(element->Attribute("type") && !strcmp(element->Attribute("type"),"POINT")) 
				isPoint = true;
			else isPoint = false;

			if(element->Attribute("X"))
				x = stof(element->Attribute("X"));
			if(element->Attribute("Y"))
				y = stof(element->Attribute("Y"));
			if(element->Attribute("Z"))
				z = stof(element->Attribute("Z"));

			light = new Light(isPoint, new Point(x,y,z));
			lights_list.push_back(light);
		}

	group->setLights(lights_list);
}


void exploreModels(XMLElement* element, Group* group){

	vector<Shape*> models_list;
	string file_model;

	element = element->FirstChildElement();
	for(;element;element=element->NextSiblingElement())
		if(!strcmp(element->Name(),"model")){

			vector<Point*> vertex_list; 
			vector<Point*> normal_list;
			vector<Point*> texture_list;

			readFile(element->Attribute("file"), &vertex_list, &normal_list, &texture_list);

			if(vertex_list.size()){
				Shape* shape;
				if(element->Attribute("texture"))
					shape = new Shape(element->Attribute("texture"), vertex_list, normal_list, texture_list);
				else 
					shape = new Shape(vertex_list, normal_list, texture_list);

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

	else if(!strcmp(element->Name(),"lights"))
		updateLights(element, group);

	else if(!strcmp(element->Name(),"models"))
		exploreModels(element, group);

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

void readFile(string file_name, vector<Point*>* vertex_list, vector<Point*>* normal_list, vector<Point*>* texture_list){

	vector<string> tokens;
	string buf;
	string line;
	int index;

	ifstream file (file_name);
	if(file.is_open()){

		index = 0;
		getline(file, line);
		int n_vertex = atoi(line.c_str());

		for(int i=0; i < n_vertex; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			
			vertex_list->push_back(new Point(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}

		index = 0;
		getline(file, line);
		int n_normal = atoi(line.c_str());

		for(int i=0; i < n_normal; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha

			normal_list->push_back(new Point(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}
		
		index = 0;
		getline(file, line);
		int n_texture = atoi(line.c_str());

		for(int i=0; i < n_texture; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			
			texture_list->push_back(new Point(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2]))); // adicionar vértice ao vector
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