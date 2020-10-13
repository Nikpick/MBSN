//
// Created by Simone on 2019-08-18.
//

#include <exception>

class TriggerTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The trigger condition must be Boolean.";
    }
};
