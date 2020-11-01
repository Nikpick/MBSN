
#include <iostream>
#include <Model/Module.h>
#include <json/json.h>
#include <json/json-forwards.h>
#include <json_reader.cpp>

int main(int argc, char const *argv[])
{
    auto jvalue = json_reader("../out.json");
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




    /*
    // FOR TESTING PURPOSES
    auto strJvalue = jvalue.toStyledString();
    auto str = strJvalue.c_str();
    printf("%s", str);
    */

    return 0;
}
 