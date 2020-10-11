//
// Created by Simone on 2019-08-28.
//

#include <exception>

class AlgorithmStatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The module hasn't an algorithm section.";
    }
};
