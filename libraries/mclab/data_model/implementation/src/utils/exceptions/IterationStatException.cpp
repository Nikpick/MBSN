//
// Created by Simone on 2019-08-27.
//

#include <exception>

class IterationStatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The iteration statement must have only one statement.";
    }
};
