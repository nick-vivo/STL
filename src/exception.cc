#include <exception.h>

mstd::exception::exception(): _message("Exception was called") {}

mstd::exception::exception(const char* message): _message(message) {}

mstd::exception::exception(const mstd::string message): _message(message) {}

const char* mstd::exception::what() const noexcept
{
    return this->_message.c_str();
}