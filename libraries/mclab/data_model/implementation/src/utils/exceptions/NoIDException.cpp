//
// Created by Simone on 19/09/2019.
//

#include <exception>

class NoIDException : public std::exception {
public:
	const char* what() const noexcept override {
		return "There isn't ID.";
	}
};
