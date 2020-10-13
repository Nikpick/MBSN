//
// Created by Simone on 2019-08-28.
//

#include <exception>

class ElseStatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The if statement hasn't an else statement.";
    }
};
