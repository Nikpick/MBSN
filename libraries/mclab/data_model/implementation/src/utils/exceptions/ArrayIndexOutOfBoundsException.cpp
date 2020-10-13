//
// Created by Simone on 04/09/2019.
//

#include <exception>

struct ArrayIndexOutOfBoundsException : public std::exception {

    const char* what() const noexcept override {
        return "Illegal access to array position (array size exceeded)";
    }

};
