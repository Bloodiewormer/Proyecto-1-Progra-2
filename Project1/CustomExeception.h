#pragma once
#include <exception>
#include <string>

// Custom exception class for IndexOutOfBoundsException
class IndexOutOfBoundsException : public std::exception {
public:
	IndexOutOfBoundsException(const std::string& message) : msg_(message) {}
	virtual const char* what() const noexcept override {
		return msg_.c_str();
	}


private:
	std::string msg_;
};

// Custom exception class for invalid input
class InvalidInputException : public std::exception {
public:
	InvalidInputException(const std::string& message) : msg_(message) {}
	virtual const char* what() const noexcept override {
		return msg_.c_str();
	}
private:
	std::string msg_;
};