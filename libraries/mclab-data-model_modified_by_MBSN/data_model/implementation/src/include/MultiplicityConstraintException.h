//
// Created by bayo on 31/08/19.
//

#ifndef CODE_C___MULTIPLICITYCONSTRAINTEXCEPTION_H
#define CODE_C___MULTIPLICITYCONSTRAINTEXCEPTION_H

#include <exception>

struct MultiplicityConstraintException : public std::exception {

    const char* what() const noexcept override {
        return "The number of links held by this StrongAssociationRole violates his Association's multiplicity constraints";
    }

};

#endif //CODE_C___MULTIPLICITYCONSTRAINTEXCEPTION_H
