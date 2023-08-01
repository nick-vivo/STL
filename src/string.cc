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

mstd::string::string(): _size(0), _capacity(__STRING_STANDART_SIZE + 1), _str(new char[this->_capacity])
{
    this->_str[0] = '\0';
}

mstd::string::string(const string& other): _size(other._size), _capacity(other._capacity), _str(new char[this->_capacity])
{
    for (mstd::t_size i = 0; i <= this->_size; ++i)
    {
        this->_str[i] = other._str[i];
    }
}

mstd::string::string(const char* str): _size(mstd::strlen(str)), _capacity(this->_size + 1), _str(new char[this->_capacity])
{
    for (mstd::t_size i = 0; i < this->_capacity; ++i)
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

//TODO: Доделать
mstd::string& mstd::string::operator=(const mstd::string& other) noexcept
{
    if (this->_capacity < other._size)
    {
    }
}

const char* mstd::string::c_str() const noexcept
{
    return this->_str;
}