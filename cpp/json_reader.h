#include "../libraries/jsoncpp/json/json.h"
#include "../libraries/jsoncpp/json/json-forwards.h"
#include "../libraries/jsoncpp/jsoncpp.cpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

Json::Value json_reader(string path);