//
// Created by Simone on 2019-08-18.
//

#include <exception>

class ParameterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "A parameter can be either 'input' and 'static'.";
    }
};
