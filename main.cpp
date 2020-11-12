

#include <iostream>
#include <fstream>
#include <string.h>
#include <Model/Module.h>
// #include <json/json.h>
// // #include <json/json-forwards.h>
// // #include <json_reader.cpp>
#include <rapidxml.hpp>
#include "parser.cpp"


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
    char xmlAsCharArray[n+1];
    strcpy(xmlAsCharArray, xmlAsString.c_str());

    xml_document<> doc;
    doc.parse<0>(xmlAsCharArray);
    // Fine del parsing: la variabile doc contiene il dizionario


    // auto mod = std::make_shared<Modeling::Module>("foo");
    auto module = Module("system");
    auto root = doc.first_node("dae");

    cout << "First node name: " << root->name() << endl;
    
    parser(&module, root);
    
    return 0;
}
