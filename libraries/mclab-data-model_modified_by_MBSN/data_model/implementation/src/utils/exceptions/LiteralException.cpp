//
// Created by Simone on 29/08/2019.
//

#include <exception>

class LiteralException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The value isn't a literal.";
    }
};
