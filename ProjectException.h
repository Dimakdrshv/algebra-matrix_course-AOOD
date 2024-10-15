#pragma once
#include <iostream>
#include <exception>

class ProjectException : public std::exception {
private:
	std::string msg;
public:
	ProjectException(std::string msg);
	const char* what() const noexcept override;
};
