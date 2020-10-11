//
// Created by Simone on 29/08/2019.
//

#include <exception>

class InitAssException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The variable already has an initial assignment.";
    }
};
