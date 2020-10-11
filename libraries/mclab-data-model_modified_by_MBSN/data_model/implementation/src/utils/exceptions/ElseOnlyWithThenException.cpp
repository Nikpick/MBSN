//
// Created by Simone on 04/09/2019.
//

#include <exception>

class ElseOnlyWithThenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Before to add an else statement add a then statement.";
    }
};
