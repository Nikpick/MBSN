
//#include "../headers/parser.h"
#include <rapidxml.hpp>
// #include "../libraries/rapidxml-1.13/rapidxml.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace Modeling;
using namespace rapidxml;
using namespace std;

//SET METHODS
void setVariables(Module* module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
    node = node->next_sibling();
    if(node) setVariables(module, doc, node);
}

//GET METHODS
void getVariables(Module* module, xml_document<>* doc, xml_node<>* node) {
    cout << node->name() << endl;
}

void parser(Module* module, xml_document<>* doc, xml_node<>* root) {
    xml_node<>* node = root->first_node();
    while(node) {
        auto nodeName = node->name();
        if(strcmp(nodeName, "variables") == 0) {
            //cout << "#" << nodeName << "#" << endl;
            cout << "ciao " << endl;
            setVariables(module, doc, node);
    
        } 
    //     else if(nodeName == "equations") {

    //     }
    //     else if(nodeName == "functions") {
            
    //     }
        node = node->next_sibling();
    }
}

