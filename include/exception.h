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

}
#endif