//
// Created by Simone on 03/09/2019.
//

#include <exception>

class NullPointerException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Illegal usage of null pointer.";
	}
};
