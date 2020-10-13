//
// Created by Simone on 03/09/2019.
//

#include <exception>

class NotInvolvedInLinkException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Can't add a link with not involved class.";
    }
};
