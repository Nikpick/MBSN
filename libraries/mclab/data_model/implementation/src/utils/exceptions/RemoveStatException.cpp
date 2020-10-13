//
// Created by Simone on 29/08/2019.
//

#include <exception>

class RemoveStatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Can't remove a statement from this statement.";
    }
};
