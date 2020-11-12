
//#include "../headers/parser.h"
#include <rapidxml.hpp>
// #include "../libraries/rapidxml-1.13/rapidxml.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace Modeling;
using namespace rapidxml;
using namespace std;

//GETTERS METHODS
void getEquations(Module* module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

void getFunctionss(Module* module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

void getVariables(Module* module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

//SETTERS METHODS

void setEquations(Module* module, xml_node<>* node) {
    
}

void setFunctions(Module* module, xml_node<>* node) {
    
}

void setAliasVariable(Module* module, xml_node<>* node) {
    cout << node->first_attribute("name")->value() << endl;
}

void setOrderedVariable(Module* module, xml_node<>* node) {
    cout << "Variabile: " << node->first_attribute("name")->value() << endl;

    std::shared_ptr<Variable> variable;

    //name
    string name = node->first_attribute("name")->value();
    
    //tipo (reale, intero ecc)
    string type = node->first_attribute("type")->value();

    //valore
}

void setVariables(Module* module, xml_node<>* node) {
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
    // chiamata riorsiva se ci sono nodi fratelli
    if(node->next_sibling()) setVariables(module, node->next_sibling());
}

void parser(Module* module, xml_node<>* root) {
    xml_node<>* node = root->first_node();
    while(node) {
        auto nodeName = node->name();
        if(strcmp(nodeName, "variables") == 0) {
            setVariables(module, node->first_node());
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

