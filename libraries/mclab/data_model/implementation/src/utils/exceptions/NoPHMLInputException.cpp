//
// Created by Simone on 17/09/2019.
//

#include <exception>

class NoPHMLInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Provide a PHML file.";
    }
};
