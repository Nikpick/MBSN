
#include <iostream>
#include <fstream>
#include <string.h>
#include <Model/Module.h>
// #include <json/json.h>
// // #include <json/json-forwards.h>
// // #include <json_reader.cpp>
#include <rapidxml.hpp>

using namespace std;
using namespace rapidxml;

int main(int argc, char const *argv[])
{
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

    auto firstNodeName = doc.first_node("dae");
    cout << "First node name: " << firstNodeName->name() << endl;

    auto mod = std::make_shared<Modeling::Module>("foo");

    return 0;
}
