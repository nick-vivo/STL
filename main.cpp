#include <iostream>
#include <memory.h>
#include <list.h>

#include <string>

using namespace std;

int main()
{

    mstd::List<int> a =  {1, 2, 3};
    

    std::cout << a[0] << ":" << a[1] << ":" << a[2];
    return 0;
}