

#include <iostream>
#include <fstream>
#include <string>
#include <Model/Module.h>
//#include <json/json.h>
//#include <json/json-forwards.h>
//#include <rapidxml.hpp>
#include "cpp\parser.h"
#include "cpp\mathML_to_string.h"
#include <sbml\SBMLTypes.h>

using namespace std;
//using namespace rapidxml;
//using namespace Modeling;
using std::cout;
using std::endl;



int main(int argc, char const *argv[])
{

    const char *s = "<math xmlns=\"http://www.w3.org/1998/Math/MathML\"> <apply> <equivalent/> <apply> <diff/> <ci> Params.b </ci> </apply> <cn type=\"real\"> 0.0 </cn> </apply> </math>";

    ASTNode* ast = readMathMLFromString(s);
    if (ast == NULL) printf("non va 1\n");

    char* result = SBML_formulaToL3String(ast);
    if (result == NULL) printf("non va 2\n");
    
    printf("ciaone %s", result);
    //cout << "String is: " << result << endl;

    //// Parsing dell'xml in dizionario
    //ifstream xml(argv[1]);
    //string xmlAsString, line;

    //while (std::getline(xml, line)) {
    //    xmlAsString.append(line);
    //}

    //int n = xmlAsString.length();
    //char xmlAsCharArray[n+1];
    //strcpy(xmlAsCharArray, xmlAsString.c_str());

    //xml_document<> doc;
    //doc.parse<0>(xmlAsCharArray);
    //// Fine del parsing: la variabile doc contiene il dizionario


    //// auto mod = std::make_shared<Modeling::Module>("foo");
    //auto module = make_shared<Module>("system");
    //auto root = doc.first_node("dae");

    ////auto root = doc.first_node("dae")->first_node("variables")->first_attribute("dimension")->value();
    //cout << "First node name: " << root->name() << endl;

    //parser(module, root);
    //mathML_to_string(module);
    //
    return 0;
}
