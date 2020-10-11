//
// Created by Simone on 2019-08-26.
//

#include <exception>
#include <string>

class VarNotInModuleException : public std::exception {
private:
    std::string msg;
public:
    explicit VarNotInModuleException(const std::string& varName) : msg(std::string("The variable ") + varName + std::string(" isn't in the module.")) {
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
