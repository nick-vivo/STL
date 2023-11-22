#include <list.h>
#include <iostream>

int main()
{
    mstd::List<int> ls = {1, 2, 3, 4};

    ls = {2, 3, 4};

    std::cout << ls[0] << ":" << ls[1] << ":" << ls[2] << ":";

    return 0;
}