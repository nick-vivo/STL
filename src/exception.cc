#include <exception.h>

mstd::exception::exception(): _message("The exception was called") {}

mstd::exception::exception(const char* message): _message(message) {}

mstd::exception::exception(const mstd::string message): _message(message) {}

const char* mstd::exception::what() const noexcept
{
    return this->_message.c_str();
}

mstd::runtime_error::runtime_error(): exception() {}

mstd::runtime_error::runtime_error(const char* message): exception(message) {}

mstd::runtime_error::runtime_error(const mstd::string message): exception(message) {}