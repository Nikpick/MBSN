//
// Created by Simone on 2019-08-28.
//

#include <exception>

class DefInOperationException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The operation already has a definition.";
    }
};
