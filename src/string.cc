#include <string.hpp>

mstd::t_size mstd::strlen(const char* str)
{
    t_size count = 0;
    while(*str)
    {
        ++str;
        ++count;
    }
    return count;
}

mstd::string::string(): _capacity(__STRING_STANDART_SIZE), _size(0), _str(new char[this->_capacity])
{
    this->_str[0] = '\0';
}

mstd::string::string(const char* str): _capacity(strlen(str)), _size(_capacity), _str(new char[this->_capacity])
{
    for (mstd::t_size i = 0; i <= this->_size; ++i)
    {
        this->_str[i] = str[i];
    }
}

mstd::string::~string()
{
    if (this->_str)
    {
        delete[] this->_str;
    }
}

const char* mstd::string::c_str() const noexcept
{
    return this->_str;
}