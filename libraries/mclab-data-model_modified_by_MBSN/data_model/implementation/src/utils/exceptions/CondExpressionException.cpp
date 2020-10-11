//
// Created by Simone on 2019-08-18.
//

#include <exception>

class CondExpressionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The type of the conditional expression must be equal to then expression and else expression.";
    }
};
