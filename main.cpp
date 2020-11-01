
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
        auto v = values.c_str();
        printf("Valori per il membro --%s--: %s\n", member.c_str(), v);
    }




    /*
    // FOR TESTING PURPOSES
    auto strJvalue = jvalue.toStyledString();
    auto str = strJvalue.c_str();
    printf("%s", str);
    */

    return 0;
}
 