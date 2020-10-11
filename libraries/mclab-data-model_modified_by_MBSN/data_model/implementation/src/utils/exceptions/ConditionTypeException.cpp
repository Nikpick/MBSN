//
// Created by Simone on 2019-08-18.
//

#include <exception>

class ConditionTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The if condition must be boolean.";
    }
};
