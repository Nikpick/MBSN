//
// Created by Simone on 18/09/2019.
//

#include <exception>

class NoTypeFoundException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Unknown type.";
	}
};
