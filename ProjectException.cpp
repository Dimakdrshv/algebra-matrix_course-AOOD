#include "ProjectException.h"

ProjectException::ProjectException(std::string msg) {
    this->msg = msg;
}

const char* ProjectException::what() const noexcept {
    return this->msg.c_str();
}
