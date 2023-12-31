#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <tools.h>

namespace mstd
{
using t_size = long int;

t_size strlen(const char* str);

#define __STRING_STANDART_SIZE 32
#define __STRING_STANDART_STEP 10
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

    string& operator=(const mstd::string& other) noexcept;

    string& operator=(const char* other) noexcept;

    string operator+(const string& other) const noexcept;

    char& operator[](t_size index);

    char& at(t_size index);

    char c_at(t_size index) const;

    const char* c_str() const noexcept;

    t_size size() const noexcept;

    t_size capacity() const noexcept;

    void swap(string& other);
};


bool operator==(const string& str_1, const string& str_2) noexcept;

bool operator==(const string& str_1, const char* str_2) noexcept;

string operator+(const string& str_1, const char* str_2) noexcept;
string operator+(const char* str_2, const string& str_1) noexcept;
}

inline char& mstd::string::operator[](mstd::t_size index)
{
    return this->_str[index];
}

inline char& mstd::string::at(t_size index)
{
    if (index >= this->_size || index < 0)
    {
        throw "Index is bad value";
    }
    return this->_str[index];
}

inline char mstd::string::c_at(t_size index) const
{
    if (index >= this->_size || index < 0)
    {
        throw "Index is bad value";
    }
    return this->_str[index];
}

inline const char* mstd::string::c_str() const noexcept
{
    return this->_str;
}

inline mstd::t_size mstd::string::size() const noexcept
{
    return this->_size;
}

inline mstd::t_size mstd::string::capacity() const noexcept
{
    return this->_capacity;
}

#endif