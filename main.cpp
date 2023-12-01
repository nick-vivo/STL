#include <list.h>
#include <iostream>
#include <sorts.hh>
#include <vector>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& stream, std::vector<T> vec)
{
    std::cout << "Vector<" << "..." << ">: {";
    
    typename std::vector<T>::iterator it = vec.begin();

    while ( it != vec.end() )
    {
        stream << *it++;

        if (it != vec.end())
        {
            stream << ", ";
        }
    }

    stream << "};\n";

    return stream;
}


template<>
std::ostream& operator<<(std::ostream& stream, std::vector<std::string> vec)
{
    std::cout << "Vector<" << "..." << ">: {";
    
    typename std::vector<std::string>::iterator it = vec.begin();

    while ( it != vec.end() )
    {

        stream <<"\"";
        stream << *it++;
        stream <<"\"";
        if (it != vec.end())
        {
            stream << ", ";
        }
    }

    stream << "};\n";

    return stream;
}

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
    mstd::List<int> ls = {4, 3, 5, 1, 5, 2 ,7 ,8, 1, 7, 3, 5, 8, 2};

    mstd::List<int> ls_2 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 7, 7, 8, 8};

    mstd::heapSort(ls.begin(), ls.end());

    std::cout << ls;

    std::cout <<"\nОни: " << (ls == ls_2) << "\n";

    return 0;
}