#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "tinyxml2.h"
#include "Group.h"
#include "Translation.h"
#include "Rotation.h"
#include "Scale.h"

using namespace std;
using namespace tinyxml2;

void updateTranslation(XMLElement*, Group*);
void updateRotation(XMLElement*, Group*);
void updateScale(XMLElement*, Group*);
void updateColourComponent(XMLElement*, Shape*);
void updateLights(XMLElement*, Group*);
void exploreElement(XMLElement*, Group*);
vector<Shape*> exploreModels(XMLElement* );
void readFile(string, vector<Point*>*, vector<Point*>*, vector<Point*>*);
Group* hereditaryChild(Group*);
Group* parseXML(char*);


#endif