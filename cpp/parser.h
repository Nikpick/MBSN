// #include "../headers/parser.h"
#include "..\libraries\rapidxml-1.13\rapidxml_print.hpp"
// #include <rapidxml_ext.h>
// #include "../libraries/rapidxml-1.13/rapidxml.hpp"
#include "..\libraries\rapidxml-1.13\rapidxml_print.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
//#include <Model\Module.h>
#include "../libraries/mclab-data-model/headers/Model/Parameter.h"
#include "../libraries/mclab-data-model/headers/Model/Species.h"
#include "../libraries/mclab-data-model/headers/Model/BaseType.h"
#include "../libraries/mclab-data-model/headers/Model/Unit.h"
#include "../libraries/mclab-data-model/headers/Model/Module.h"
#include <memory>

using namespace std;
using namespace rapidxml;
//using namespace Modeling;

shared_ptr<Modeling::Type> find_basetype(const std::string &typeStr);
void setEquations(shared_ptr<Modeling::Module> module, xml_node<> *node);
void setFunctions(shared_ptr<Modeling::Module> module, xml_node<> *node);
void setAliasVariable(shared_ptr<Modeling::Module> module, xml_node<> *node);
void setOrderedVariable(shared_ptr<Modeling::Module> module, xml_node<> *node);
void setVariables(shared_ptr<Modeling::Module> module, xml_node<> *node);
void parser(shared_ptr<Modeling::Module> module, xml_node<> *root);