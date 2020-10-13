//
// Created by Simone on 2019-08-18.
//

#include <exception>

class DelayTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The delay must be numeric.";
    }
};
