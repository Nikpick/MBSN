
// #include "../headers/parser.h"
#include <rapidxml.hpp>
// #include "../libraries/rapidxml-1.13/rapidxml.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <Parameter.h>
#include <Species.h>
#include <BaseType.h>
#include <Unit.h>
#include <memory>

using namespace Modeling;
using namespace rapidxml;
using namespace std;

//GETTERS METHODS
void getEquations(shared_ptr<Module> module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

void getFunctionss(shared_ptr<Module> module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

void getVariables(shared_ptr<Module> module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

//SETTERS METHODS

std::shared_ptr<Modeling::Type> find_basetype(const std::string& typeStr) {
	std::shared_ptr<Modeling::Type> type;
	if(typeStr == "Real")
		type = std::make_shared<Modeling::BaseType>("Real");
	else if(typeStr == "integer")
		type = std::make_shared<Modeling::BaseType>("Integer");
	else if (typeStr == "bool")
		type = std::make_shared<Modeling::BaseType>("Boolean");
	else if (typeStr == "string")
		type = std::make_shared<Modeling::BaseType>("String");
	else
	    // throw NoTypeFoundException();
        cout << "Type \"" << typeStr << "\" not found." << endl;
	return type;
}

void setEquations(shared_ptr<Module> module, xml_node<>* node) {
    
}

void setFunctions(shared_ptr<Module> module, xml_node<>* node) {
    
}

void setAliasVariable(shared_ptr<Module> module, xml_node<>* node) {
    cout << node->first_attribute("name")->value() << endl;
}

void setOrderedVariable(shared_ptr<Module> module, xml_node<>* node) {
    cout << "Variabile: " << node->first_attribute("name")->value() << endl;

    // name
    string name = node->first_attribute("name")->value();
    // tipo (reale, intero ecc)
    string typeStr = node->first_attribute("type")->value();
    auto type = find_basetype(typeStr);
    // unit
    shared_ptr<Unit> mele = make_shared<Unit>("pesche");
    // fixed
    string fixed = node->first_attribute("fixed")->value();
    // differentiatedIndex
    bool diff = strcmp(node->first_attribute("differentiatedIndex")->value(), "1") ? true : false;


    //inizializzazione variabile
    std::shared_ptr<Variable> parippappaparippari;
    if (name == "myclass.z") {
        parippappaparippari = make_shared<Parameter>(name, mele, type);
        parippappaparippari->setModule(module);
        cout << module->getVars().size() << "#############" << endl;

        // cout << module->getVars() << edl;
    }

    //valore
}

void setVariables(shared_ptr<Module> module, xml_node<>* node) {
    cout << "# inizio set variable" << endl;

    xml_node<>* variableNode = node->first_node()->first_node();
    if(strcmp(node->name(), "orderedVariables") == 0) {
        while(variableNode) { // Per ogni <variable> in <variablesList>
            setOrderedVariable(module, variableNode);

            variableNode = variableNode->next_sibling();
        }
    }
    else if(strcmp(node->name(), "aliasVariables") == 0) {
        
    }
    
    cout << "# fine set variable" << endl;
    // chiamata ricorsiva se ci sono nodi fratelli
    if(node->next_sibling()) setVariables(module, node->next_sibling());
}

void parser(shared_ptr<Module> module, xml_node<>* root) {
    xml_node<>* node = root->first_node();
    while(node) {
        auto nodeName = node->name();
        if(strcmp(nodeName, "variables") == 0) {
            setVariables(module, node->first_node());
            auto vars = module->getVars();
            for(auto it = 0; it < module->getVars().size(); it++) {
                cout << it+1 << endl;
            }
        } 
        else if(strcmp(nodeName, "equations") == 0) {
            setEquations(module, node->first_node());
        }
        else if(strcmp(nodeName, "functions") == 0) {
            setFunctions(module, node->first_node());
        }
        else cout << nodeName << " not found." << endl;
        
        node = node->next_sibling();
    }
}

