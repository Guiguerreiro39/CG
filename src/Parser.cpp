#include "headers/Parser.h"

int total_groups = 0;

Group* hereditaryChild(Group* father){

	Group* son = new Group(total_groups++);
	father->addChild(son);

	return son;
}

void updateTranslation(XMLElement* element, Group* group){

	float x=0, y=0, z=0, time=0;

	if(element->Attribute("time"))
		time = stof(element->Attribute("time"));

	if(element->Attribute("X")) 
		x = stof(element->Attribute("X"));

	if(element->Attribute("Y")) 
		y = stof(element->Attribute("Y"));

	if(element->Attribute("Z")) 
		z = stof(element->Attribute("Z"));

	Translation* translation = new Translation(x, y, z, time);

	XMLElement* point_element = element->FirstChildElement();

	for(;point_element;point_element=point_element->NextSiblingElement()){
		float p_x=0, p_y=0, p_z=0;

		if(point_element->Attribute("X")) 
			p_x = stof(point_element->Attribute("X"));
		if(point_element->Attribute("Y")) 
			p_y = stof(point_element->Attribute("Y"));
		if(point_element->Attribute("Z")) 
			p_z = stof(point_element->Attribute("Z"));

		Point* point = new Point(p_x, p_y, p_z);
		translation->addPoint(point);
	}

	group->addOperation(translation);
}

void updateRotation(XMLElement* element, Group* group){

	float x=0, y=0, z=0, time=0, angle=0;

	if(element->Attribute("angle"))
		angle = stof(element->Attribute("angle"));
	if(element->Attribute("time"))
		time = stof(element->Attribute("time"));
	if(element->Attribute("X"))
		x = stof(element->Attribute("X"));
	if(element->Attribute("Y"))
		y = stof(element->Attribute("Y"));
	if(element->Attribute("Z"))
		z = stof(element->Attribute("Z"));

	Rotation* rotation = new Rotation(angle, time, x, y, z);
	group->addOperation(rotation);
}

void updateScale(XMLElement* element, Group* group){

	float x=0, y=0, z=0;

	if(element->Attribute("X")) 
		x = stof(element->Attribute("X"));
	if(element->Attribute("Y")) 
		y = stof(element->Attribute("Y"));
	if(element->Attribute("Z")) 
		z = stof(element->Attribute("Z"));

	Scale* scale = new Scale(x, y, z);
	group->addOperation(scale);
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

			/**for(int i = 0; i < normal_list.size(); i++){
				Point* p = normal_list[i];
				cout << p->getX() << " | " << p->getY() << " | " << p->getZ() << endl;
			}**/

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

	vector<string> tokens_v, tokens_n, tokens_t;
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
				tokens_v.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			
			vertex_list->push_back(new Point(stof(tokens_v[index]),stof(tokens_v[index+1]),stof(tokens_v[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}


		index = 0;
		getline(file, line);
		int n_normal = atoi(line.c_str());

		for(int i=0; i < n_normal; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf) 
				tokens_n.push_back(buf); // percorrer as coordenadas dos vértices em cada linha

			normal_list->push_back(new Point(stof(tokens_n[index]),stof(tokens_n[index+1]),stof(tokens_n[index+2]))); // adicionar vértice ao vector
			index+=3; // incrementar o índice
		}
		
		index = 0;
		getline(file, line);
		int n_texture = atoi(line.c_str());

		for(int i=0; i < n_texture; i++){
			getline(file,line);
			stringstream ss(line); 
			while(ss >> buf)
				tokens_t.push_back(buf); // percorrer as coordenadas dos vértices em cada linha
			
			texture_list->push_back(new Point(stof(tokens_t[index]),stof(tokens_t[index+1]),0)); // adicionar vértice ao vector
			index+=2; // incrementar o índice
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
		element = doc.FirstChildElement("scene")->FirstChildElement("lights");
		if(element) updateLights(element,group);
		element = doc.FirstChildElement("scene")->FirstChildElement("group");
		exploreElement(element,group);
	}
	else
		cout << "Could not load XML file: " << file_name << "." << endl;

	return group;
}