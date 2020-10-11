//
// Created by Simone on 22/09/2019.
//

#include <exception>
#include <string>

class NotSupportedException : public std::exception {
private:
	std::string msg;
public:
	explicit NotSupportedException(const std::string& field) : msg(std::string("The ") + field + std::string(" is unsupported.")) {
	}
	const char* what() const noexcept override {
		return msg.c_str();
	}
};
