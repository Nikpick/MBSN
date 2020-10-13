//
// Created by Simone on 2019-08-26.
//

#include <exception>

class AssInEventException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The assignment is already in the event.";
    }
};
