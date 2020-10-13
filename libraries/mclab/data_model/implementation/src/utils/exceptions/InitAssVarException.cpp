//
// Created by Simone on 2019-08-26.
//

#include <exception>
#include <string>

class InitAssVarException : public std::exception {
private:
    std::string msg;
public:
    explicit InitAssVarException(const std::string& varName) : msg(std::string("The initial assignment doesn't belong to the variable ") + varName) {
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
