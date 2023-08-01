#ifndef __STRING_HPP__
#define __STRING_HPP__

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

    const char* c_str() const noexcept;
};

}

#endif