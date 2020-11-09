

#include <rapidxml.hpp>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace Modeling;
using namespace rapidxml;
using namespace std;



void parser(Module* module, xml_document<>* doc, xml_node<>* root) {
    
    shared_ptr<Variable> variable;
    string test = "test";

    //setters
    // module.setName("ciao");
    // module.addExpression(test);
    // module->addModExpr(variable);

    // //getters
    // module.getName();
    // module.getOperations();
    // module.getVars();
    // module.getModExpr();
    // module.getOperations();
    // module.getExpression();

    return;
}

