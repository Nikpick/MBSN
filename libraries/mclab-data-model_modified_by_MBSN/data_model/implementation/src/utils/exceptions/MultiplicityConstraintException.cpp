//
// Created by Simone on 02/09/2019.
//

#include <exception>

class MultiplicityConstraintException : public std::exception {

    const char* what() const noexcept override {
        return "Adding a link would violate this Association's multiplicity constraints";
    }

};