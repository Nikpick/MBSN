//
// Created by Simone on 2019-08-28.
//

#include <exception>

class WhenStatOwnerException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The while statement isn't the owner of the statement.";
    }
};
