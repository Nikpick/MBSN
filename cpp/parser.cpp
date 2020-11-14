
//#include "../headers/parser.h"
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

void setEquations(shared_ptr<Module> module, xml_node<>* node) {
    
}

void setFunctions(shared_ptr<Module> module, xml_node<>* node) {
    
}

void setAliasVariable(shared_ptr<Module> module, xml_node<>* node) {
    cout << node->first_attribute("name")->value() << endl;
}

void setOrderedVariable(shared_ptr<Module> module, xml_node<>* node) {
    cout << "Variabile: " << node->first_attribute("name")->value() << endl;

    //name
    string name = node->first_attribute("name")->value();
    
    //tipo (reale, intero ecc)
    string type = node->first_attribute("type")->value();
    shared_ptr<BaseType> real = make_shared<BaseType>("Real");
    
    // unit
    shared_ptr<Unit> mele = make_shared<Unit>("pesche");

    //inizializzazione variabile
    std::shared_ptr<Variable> foobar;
    if (name == "myclass.z") {
        foobar = make_shared<Parameter>(name, &mele, &real);
        // foobar->setModule(module); //secondo me non compila
        //CIAOOOOOOOOOONE
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
    // chiamata riorsiva se ci sono nodi fratelli
    if(node->next_sibling()) setVariables(module, node->next_sibling());
}

void parser(shared_ptr<Module> module, xml_node<>* root) {
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

