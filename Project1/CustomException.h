#pragma once
#include <exception>
#include <string>

// Custom exception class for IndexOutOfBoundsException
class IndexOutOfBoundsException : public std::exception {
private:
	std::string msg_;
public:
	IndexOutOfBoundsException(const std::string& message);
	virtual const char* what() const noexcept override;
};

// Custom exception class for invalid input
class InvalidInputException : public std::exception {
private:
	std::string msg_;
public:
	InvalidInputException(const std::string& message);
	virtual const char* what() const noexcept override;
};

// Custom exception class for error in file operations
class FileOperationException : public std::exception {
private:
	std::string msg_;
public:
	FileOperationException(const std::string& message);
	virtual const char* what() const noexcept override;
};

// Custom exception class for creating objects

class ObjectCreationException : public std::exception {
private:
	std::string msg_;
public:
	ObjectCreationException(const std::string& message);
	virtual const char* what() const noexcept override;
};

// Custom exception class for invalid date
class InvalidDateException : public std::exception {
private:
	std::string msg_;
public:
	InvalidDateException(const std::string& message);
	virtual const char* what() const noexcept override;
};


