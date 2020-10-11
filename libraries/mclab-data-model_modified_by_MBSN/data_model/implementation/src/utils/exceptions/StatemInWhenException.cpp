//
// Created by Simone on 2019-08-28.
//

#include <exception>

class StatemInWhenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "A statement with the same condition is already in when statement.";
    }
};
