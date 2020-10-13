//
// Created by Simone on 05/09/2019.
//

#include <exception>

class ArgumentInOtherFunctionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The argument is already in another operation.";
    }
};
