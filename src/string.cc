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
        this->_size = other._size;
    }
    return *this;
}

mstd::string& mstd::string::operator=(const char* other) noexcept
{
    t_size other_size = strlen(other);
    if (this->_capacity < other_size + 1)
    {
        string tmp(other);
        this->swap(tmp);
    }
    else
    {
        for(mstd::t_size i = 0; i <= other_size; ++i)
        {
            this->_str[i] = other[i];
        }
        this->_size = other_size;
    }
    return *this;

}


void mstd::string::swap(string& other)
{
    mstd::swap(this->_str, other._str);
    mstd::swap(this->_size, other._size);
    mstd::swap(this->_capacity, other._capacity);
}

//out string
bool mstd::operator==(const mstd::string& str_1, const char* str_2) noexcept
{
    if(str_1.size() != mstd::strlen(str_2))
    {
        return false;
    }
    for (mstd::t_size i = 0; i < str_1.size(); ++i)
    {
        if (str_1.c_at(0) != str_2[i])
        {
            return false;
        }
    }
    return true;
}

// bool mstd::operator==(const mstd::string& str_1, const mstd::string& str_2) noexcept
// {
//     if(str_1.size() != str_2.size())
//     {
//         return false;
//     }
//     for (mstd::t_size i = 0; i < str_1.size(); ++i)
//     {
//         if (str_1.c_at(i) != str_2.c_at(i))
//         {
//             return false;
//         }
//     }
//     return true;
// }