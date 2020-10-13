//
// Created by Simone on 05/09/2019.
//

#include <exception>

class StatementWithOwnerException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The statement already has an owner.";
    }
};
