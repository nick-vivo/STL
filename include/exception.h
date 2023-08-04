#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string.hpp>

namespace mstd
{

class exception
{
private:
    mstd::string _message;
public:
    exception();

    exception(const char* message);

    exception(const mstd::string message);

    const char* what() const noexcept;
};

class runtime_error: public exception
{
public:
    runtime_error();
    runtime_error(const char* message);
    runtime_error(const mstd::string message);
};

}
#endif