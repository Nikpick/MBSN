//
// Created by Simone on 2019-08-28.
//

#include <exception>

class ElseAlreadyInException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The else statement is already in the conditional statement.";
    }
};
