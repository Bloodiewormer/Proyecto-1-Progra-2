#include "CustomException.h"

IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& message) : msg_(message) {}

const char* IndexOutOfBoundsException::what() const noexcept
{
	return msg_.c_str();
}

InvalidInputException::InvalidInputException(const std::string& message) :msg_(message) {}

const char* InvalidInputException::what() const noexcept
{
	return msg_.c_str();
}

FileOperationException::FileOperationException(const std::string& message) :msg_(message) {}

const char* FileOperationException::what() const noexcept
{
	return msg_.c_str();
}

ObjectCreationException::ObjectCreationException(const std::string& message) :msg_(message) {}
const char* ObjectCreationException::what() const noexcept
{
	return msg_.c_str();
}
