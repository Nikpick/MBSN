//
// Created by Simone on 2019-08-27.
//

#include <exception>

class StatementOwnerException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The statement already has an owner.";
    }
};
