//
// Created by Simone on 2019-08-27.
//

#include <exception>

class TypeVarInConnException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The variables involved in connection must have the same type.";
    }
};
