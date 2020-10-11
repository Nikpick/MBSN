#ifndef CODE_C___ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
#define CODE_C___ARRAYINDEXOUTOFBOUNDSEXCEPTION_H

#include <exception>

struct ArrayIndexOutOfBoundsException : public std::exception {

    const char* what() const noexcept override {
        return "Illegal access to array position (array size exceeded)";
    }

};


#endif //CODE_C___ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
