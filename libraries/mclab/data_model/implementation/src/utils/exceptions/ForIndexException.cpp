//
// Created by Simone on 2019-08-18.
//

#include <exception>

class ForIndexException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The field begin, step and up to must be numeric.";
    }
};
