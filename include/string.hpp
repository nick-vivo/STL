#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <tools.h>

namespace mstd
{
using t_size = long int;

t_size strlen(const char* str);

#define __STRING_STANDART_SIZE 32
class string
{
private:
    t_size  _size, _capacity;
    char* _str;

public:

    string();

    string(const string& str);

    string(const char* str);

    ~string();

    string& operator=(const string& other) noexcept;

    string& operator=(const char* other) noexcept;

    char& operator[](t_size index);

    char& at(t_size index);

    const char* c_str() const noexcept;

    t_size size() const noexcept;

    t_size capacity() const noexcept;

    void swap(string& other);
};

}

#endif