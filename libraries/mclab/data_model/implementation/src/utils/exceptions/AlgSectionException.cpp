//
// Created by Simone on 2019-08-27.
//

#include <exception>

class AlgSectionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "There's no algorithm section in the module.";
    }
};
