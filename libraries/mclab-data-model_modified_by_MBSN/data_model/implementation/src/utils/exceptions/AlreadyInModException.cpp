//
// Created by Simone on 2019-08-26.
//

#include <exception>
#include <string>

class AlreadyInModException : public std::exception {
private:
    std::string msg;
public:
    explicit AlreadyInModException(const std::string& field) : msg(std::string("The ") + field + std::string(" is already in the Module.")) {
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
