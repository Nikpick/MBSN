//
// Created by Simone on 16/09/2019.
//

#include <exception>

class NoStatementException : public std::exception {
public:
    const char* what() const noexcept override {
        return "There is no statement.";
    }
};
