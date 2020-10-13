//
// Created by Simone on 20/09/2019.
//

#include <exception>

class NoModuleConnectionException : public std::exception {
public:
	const char* what() const noexcept override {
		return "No module found for connection.";
	}
};