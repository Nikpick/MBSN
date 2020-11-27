
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

//Come memorandum per xml:
// '&' --> '&amp;'
// '<' --> '&lt;'
// '>' --> '&gt;'
// '"' --> '&quot'

std::shared_ptr<Modeling::Type> find_basetype(const std::string &typeStr)
{
    std::shared_ptr<Modeling::Type> type;
    if (typeStr == "Real")
        type = std::make_shared<Modeling::BaseType>("Real");
    else if (typeStr == "Integer")
        type = std::make_shared<Modeling::BaseType>("Integer");
    else if (typeStr == "Bool")
        type = std::make_shared<Modeling::BaseType>("Boolean");
    else if (typeStr == "String")
        type = std::make_shared<Modeling::BaseType>("String");
    else
        // throw NoTypeFoundException();
        cout << "Type \"" << typeStr << "\" not found." << endl;
    return type;
}

void setEquations(shared_ptr<Module> module, xml_node<> *node)
{
    if (strcmp(node->name(), "equation") == 0) {
        // estrazione dell'espressione sotto forma di stringa
        auto expr = node->value();
        module->addExpression(expr);
        cout << expr << endl;
    }
    if (strcmp(node->name(), "algorithm") == 0) {
        auto alg = node->value();
        // Come gestire i nodi <algorithm> ???
        cout << alg << endl;
    }

    // chiamata ricorsiva se ci sono nodi fratelli
    if (node->next_sibling())
        setEquations(module, node->next_sibling());
}

void setFunctions(shared_ptr<Module> module, xml_node<> *node)
{
    cout << "# inizio set functions" << endl;
    xml_node<> *functionNode = node->first_node();
    while (functionNode)
    { // Per ogni <variable> in <variablesList>
        auto nomeFunzione = node->first_attribute("name")->value();
        auto closureString = string("end ") + nomeFunzione;
        string str = functionNode->value();
        unsigned first = str.find("algorithm");
        unsigned veryFirst = first + 11;
        unsigned last = str.find(closureString);
        string algo = str.substr(veryFirst,last-veryFirst);

        
        cout << "Algoritmo: " << algo << "\n";

        functionNode = functionNode->next_sibling();
    }

    cout << "# fine set functions" << endl;

    // chiamata ricorsiva se ci sono nodi fratelli
    if (node->next_sibling())
        setFunctions(module, node->next_sibling());
}

void setAliasVariable(shared_ptr<Module> module, xml_node<> *node)
{
    cout << node->first_attribute("name")->value() << endl;
}

void setOrderedVariable(shared_ptr<Module> module, xml_node<> *node)
{
    std::shared_ptr<Variable> parippappaparippari;

    // name
    auto name = node->first_attribute("name")->value();
    // tipo (reale, intero ecc)
    auto typeStr = node->first_attribute("type")->value();
    auto type = find_basetype(typeStr);
    // unit
    // shared_ptr<Unit> unit = make_shared<Unit>("");
    auto unit = make_shared<Unit>("");
    // fixed
    auto fixed = strcmp(node->first_attribute("fixed")->value(), "true") ? true : false;
    // differentiatedIndex
    auto diff = false;
    if (node->first_attribute("differentiatedIndex"))
        diff = true;
    // inp
    auto inp = false; // ????
    // out
    auto out = false; // ????

    //inizializzazione variabile
    if (diff)
    { // Specie
        parippappaparippari = make_shared<Species>(name, unit, type);
    }
    else
    { // Parameter
        parippappaparippari = make_shared<Parameter>(name, unit, type, inp, out, fixed);
    }
    parippappaparippari->setModule(module);

    // if (name == "myclass.z") {
    //     parippappaparippari = make_shared<Parameter>(name, unit, type);
    //     parippappaparippari->setModule(module);
    //     cout << module->getVars().size() << "#############" << endl;
    //     // cout << module->getVars() << edl;
    // }
}

void setVariables(shared_ptr<Module> module, xml_node<> *node)
{
    cout << "# inizio set variable" << endl;

    xml_node<> *variableNode = node->first_node()->first_node();
    if (strcmp(node->name(), "orderedVariables") == 0)
    {
        while (variableNode)
        { // Per ogni <variable> in <variablesList>
            setOrderedVariable(module, variableNode);

            variableNode = variableNode->next_sibling();
        }
    }
    else if (strcmp(node->name(), "aliasVariables") == 0)
    {
        // Come gestire le aliasVariables????
    }

    cout << "# fine set variable" << endl;
    // chiamata ricorsiva se ci sono nodi fratelli
    if (node->next_sibling())
        setVariables(module, node->next_sibling());
}

void parser(shared_ptr<Module> module, xml_node<> *root)
{
    xml_node<> *node = root->first_node();
    while (node)
    {
        auto nodeName = node->name();
        if (strcmp(nodeName, "variables") == 0)
        {
            //if(node->first_node()) setVariables(module, node->first_node());
            //auto vars = module->getVars();
            //per debug
            //for(auto it = 0; it < module->getVars().size(); it++) {
            //    cout << it+1 << endl;
            //}
            //fine debug
        }
        else if (strcmp(nodeName, "equations") == 0)
        {
            if (node->first_node())
                setEquations(module, node->first_node());
            for(auto it = 0; it < module->getExpression().size(); it++) {
                cout << it+1 << ") " + module->getExpression()[it] << endl;
            }
        }
        else if (strcmp(nodeName, "functions") == 0)
        {
            if (node->first_node())
                setFunctions(module, node->first_node());
        }
        else
            cout << nodeName << " not found." << endl;

        node = node->next_sibling();
    }
}
