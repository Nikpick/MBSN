//
// Created by Simone on 2019-08-18.
//

#include <exception>

class WhileCondTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The while condition must be Boolean.";
    }
};
