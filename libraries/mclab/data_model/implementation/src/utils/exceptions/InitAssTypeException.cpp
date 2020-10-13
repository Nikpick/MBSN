//
// Created by Simone on 29/08/2019.
//

#include <exception>

class InitAssTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The variable's type and the initial assignment's type must be equal.";
    }
};
