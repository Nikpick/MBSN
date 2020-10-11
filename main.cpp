/*
File creato da MDG, SM, BD e NG

REQUISITI:
usare CMake Tools di Visual Studio Code per compilare ed eseguire il codice,
altrimenti installare libreria jsoncpp, usare compilatore g++ ed eseguire
il link alla libreria.
*/

#include "cpp/json_reader.cpp"
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    auto modello = read_and_parse("./out.json"); // partendo dal json, otteniamo il dizionario corrispondente
    std::string data_error = "Data not found, replaced"; // stringa di default in caso di accesso ad una chiave inesistente
    
    for (auto const& id : modello["dae"].getMemberNames()) {
        std::cout << id << std::endl;
    }

    //std::cout << modello.get("dae",  data_error).get("variables",  data_error) << std::endl;

    return 0;
}