//
// Created by Simone on 2019-08-28.
//

#include <exception>

class StatNotInWhenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The statement isn't in the when statement.";
    }
};
