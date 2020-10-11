//
// Created by Simone on 2019-08-27.
//

#include <exception>

class StatInBlockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The new statement is already in the statement.";
    }
};
