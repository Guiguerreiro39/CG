#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "tinyxml2.h"
#include "Shape.h"
#include "Group.h"
#include "Vertex.h"

using namespace std;
using namespace tinyxml2;

void updateTranslation(XMLElement*, Group*);
void updateRotation(XMLElement*, Group* );
void updateScale(XMLElement*, Group* );
void exploreElement(XMLElement*, Group*);
vector<Shape*> exploreModels(XMLElement* );
vector<Vertex*> readFile(string);
Group* hereditaryChild(Group*);
Group* parseXML(char*);


#endif