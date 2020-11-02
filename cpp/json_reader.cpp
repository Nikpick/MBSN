
#include "../libraries/jsoncpp/json/json.h"
#include "../libraries/jsoncpp/json/json-forwards.h"
#include "../libraries/jsoncpp/jsoncpp.cpp"
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

// Json::Value json_reader(string path) {
Json::Value json_reader(string path) {

    Json::Value modello;                                                // DICHIARAZIONE VARIABILI
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();                 // ALLOCAZIONE
    std::string line, text, errors;                             

    std::ifstream file(path, std::ifstream::binary);                    // LETTURA DEL JSON IN INPUT
    while (std::getline(file, line)) {                                  // CONVERSIONE DEL JSON IN STRINGA
        text.append(line);
        //printf("%s", line.c_str());                                   // TEST DI LETTURA SU TERMINALE
    }

    bool parsingSuccessful = reader->parse(                             // PARSING DEL JSON IN VALUE &
        text.c_str(),                                                   // ASSEGNAZIONE A UN BOOLEANO
        text.c_str() + text.size(),
        &modello,
        &errors
    );

    delete reader;
 
    if ( !parsingSuccessful ) {                                         // CHECK SE ESITO NEGATIVO PARSING
        std::cout << "Failed to parse the JSON, errors:" << std::endl;
        std::cout << errors << std::endl;
    } else {
        printf("\nJson_parser:\tSuccess\n");
    }

    return modello;
}


