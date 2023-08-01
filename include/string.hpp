#ifndef __STRING_HPP__
#define __STRING_HPP__

namespace mstd
{
using t_size = long int;

t_size strlen(const char* str);

// #define __STRING_STANDART_SIZE 32
// class string
// {
// private:
//     t_size _capacity, _size;
//     char* _str;

// public:

//     string(): _capacity(__STRING_STANDART_SIZE), _size(0), _str(new char[this->_capacity]) {}

//     string(const char* str): _capacity(strlen(str)), _size(_capacity), _str(new char[this->_capacity]) {}

// };

}

#endif