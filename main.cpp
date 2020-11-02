
#include <iostream>
#include <Model/Module.h>
#include <json/json.h>
#include <json/json-forwards.h>
#include <json_reader.cpp>

#include <fstream>

int main(int argc, char const *argv[])
{
    // Lettura del json e conversione in Json::Value
    Json::Value json;
    std::ifstream config_doc("./out.json", std::ifstream::binary);
    config_doc >> json;
    // Metodo alternativo:
    // auto json = json_reader("./out.json");

    // Test di accesso alle componenti
    auto test = json["dae"]["variables"].toStyledString();
    cout << "Test 'json[\"dae\"][\"variables\"]':\n" << test << "\nFine test." << endl;

    /*
    auto vec = jvalue.getMemberNames();
    for (auto &member : vec) {
        auto values = jvalue[member.c_str()].toStyledString();
        auto v1 = values.c_str();
        //printf("Valori per il membro --%s--: %s\n", member.c_str(), v1);

        for (auto & val : jvalue[member.c_str()]) {
            auto v2 = val.toStyledString();
            printf("Singolo valore per --%s--:\n", member.c_str());            
            printf("%s\n\n", v2.c_str());
            
            auto vec2 = val.getMemberNames();
            for (auto & innerV : vec2) {
                auto v3 = val[innerV.c_str()].toStyledString();
                printf("Singolo valore per valore --%s--:\n", innerV.c_str());            
                printf("%s\n\n", v3.c_str());
            }
        }
    }
    // FOR TESTING PURPOSES
    auto strJvalue = jvalue.toStyledString();
    auto str = strJvalue.c_str();
    printf("%s", str);
    */

    return 0;
}
 