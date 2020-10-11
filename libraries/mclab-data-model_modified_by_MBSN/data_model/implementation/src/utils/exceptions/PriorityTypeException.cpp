//
// Created by Simone on 2019-08-18.
//

#include <exception>

class PriorityTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The priority must be numeric.";
    }
};
