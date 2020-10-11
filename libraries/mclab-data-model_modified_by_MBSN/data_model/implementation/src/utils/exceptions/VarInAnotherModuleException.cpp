//
// Created by Simone on 05/09/2019.
//

#include <exception>

class VarInAnotherModuleException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The variable is already in another module.";
    }
};
