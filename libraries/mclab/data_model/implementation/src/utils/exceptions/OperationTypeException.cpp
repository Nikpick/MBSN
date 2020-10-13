//
// Created by Simone on 29/08/2019.
//

#include <exception>

class OperationTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The operation call type must be equal to referred operation.";
    }
};
