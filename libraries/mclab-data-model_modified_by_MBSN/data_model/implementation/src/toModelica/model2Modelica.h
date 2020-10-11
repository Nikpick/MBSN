//
// Created by Simone on 08/10/2019.
//

#ifndef SRC_MODEL2MODELICA_H
#define SRC_MODEL2MODELICA_H

#include <Model/Module.h>
#include <memory>
#include <unordered_map>

class model2Modelica {
private:
	static bool isBaseType(const std::shared_ptr<Modeling::Variable>& var);
	std::string stopTime;
	std::string method;
public:
	model2Modelica(const std::string& filepath, std::unordered_map<std::string, std::shared_ptr<Modeling::Module>> modules, const std::string& stopTime, const std::string& method);
};


#endif //SRC_MODEL2MODELICA_H
