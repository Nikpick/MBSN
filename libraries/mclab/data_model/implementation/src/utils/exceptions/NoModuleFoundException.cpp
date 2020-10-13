//
// Created by Simone on 20/09/2019.
//

#include <exception>

class NoModuleFoundException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Unknown Module.";
	}
};
