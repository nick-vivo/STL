#include <list.h>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& stream, mstd::List<T> vec)
{
    std::cout << "List<" << "..." << ">: {";
    
    for(int i = 0; i < vec.size(); ++i)
    {
        stream << vec[i];

        if (i != vec.size() - 1)
        {
            stream << ", ";
        }
    }

    stream << "};\n";

    return stream;
}

int main()
{
    mstd::List<int> ls = {1, 2, 3, 4};

    auto b = ls.begin();
    auto e = ls.end();

    std::cout << *b;
    return 0;
}