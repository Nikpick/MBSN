//
// Created by Simone on 2019-08-27.
//

#include <exception>

class EqualsVarInConnException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The variables involved in connection must be different.";
    }
};
