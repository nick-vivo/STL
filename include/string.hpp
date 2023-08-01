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
    t_size _capacity, _size;
    char* _str;

public:

    string();

    string(const char* str);

    ~string();

    string& operator=(const string& other);

    const char* c_str() const noexcept;
};

}

#endif