#include <string.hpp>
//functions
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

//class string
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

mstd::string& mstd::string::operator=(const mstd::string& other) noexcept
{
    if (this->_capacity < other._size + 1)
    {
        string tmp(other);
        this->swap(tmp);
    }
    else
    {
        for(mstd::t_size i = 0; i <= other._size; ++i)
        {
            this->_str[i] = other._str[i];
        }
    }
    return *this;
}

//TODO: доделать
mstd::string& mstd::string::operator=(const char* other) noexcept
{

}

char& mstd::string::operator[](mstd::t_size index)
{
    return this->_str[index];
}

char& mstd::string::at(t_size index)
{
    if (index >= this->_size || index < 0)
    {
        throw "Index is bad value";
    }
    return this->_str[index];
}


const char* mstd::string::c_str() const noexcept
{
    return this->_str;
}

mstd::t_size mstd::string::size() const noexcept
{
    return this->_size;
}

mstd::t_size mstd::string::capacity() const noexcept
{
    return this->_capacity;
}

void mstd::string::swap(string& other)
{
    mstd::swap(this->_str, other._str);
    mstd::swap(this->_size, other._size);
    mstd::swap(this->_capacity, other._capacity);
}