/*
File creato da MDG, SM, BD e NG

NECESSARIO:
sudo apt-get install libjsoncpp-dev
*/

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::ifstream file_input("out.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(file_input, root);
    std::cout << root;

    return 0;
}