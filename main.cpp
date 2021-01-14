

#include <iostream>
#include <fstream>
#include <string>
#include <Model/Module.h>
#include <json/json.h>
#include <json/json_features.h>
#include "libraries/vcpkg/installed/x86-windows/include/rapidxml/rapidxml.hpp"
#include "cpp\parser.h"
#include "cpp\mathML_to_string.h"
#include <sbml\SBMLTypes.h>

using namespace std;
using namespace rapidxml;
using namespace Modeling;



int main(int argc, char const *argv[])
{

    // Parsing dell'xml in dizionario
    ifstream xml(argv[1]);
    string xmlAsString, line;

    while (std::getline(xml, line)) {
       xmlAsString.append(line);
    }

    int n = xmlAsString.length();
    char xmlAsCharArray[100+1];
    strcpy(xmlAsCharArray, xmlAsString.c_str());

    xml_document<> doc;
    doc.parse<0>(xmlAsCharArray);
    // Fine del parsing: la variabile doc contiene il dizionario


    // auto mod = std::make_shared<Modeling::Module>("foo");
    auto module = make_shared<Module>("system");
    auto root = doc.first_node("dae");

    //auto root = doc.first_node("dae")->first_node("variables")->first_attribute("dimension")->value();
    cout << "First node name: " << root->name() << endl;

    parser(module, root);
    mathML_to_string(module);
    
    return 0;
}
