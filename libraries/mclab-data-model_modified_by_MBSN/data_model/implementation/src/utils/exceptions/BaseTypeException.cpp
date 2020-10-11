//
// Created by Simone on 2019-08-17.
//

#include <exception>
#include <string>

class BaseTypeException : public std::exception {
private:
    std::string msg;
public:
    explicit BaseTypeException(const std::string& typeName) : msg(std::string("The type ") + typeName + std::string(" isn't built-in.")) {
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
