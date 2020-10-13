//
// Created by Simone on 29/08/2019.
//

#include <exception>
#include <string>

class OpNotInModException : public std::exception {
private:
    std::string msg;
public:
    explicit OpNotInModException(const std::string& opName) : msg(std::string("The operation ") + opName + std::string(" isn't in the module.")) {
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
