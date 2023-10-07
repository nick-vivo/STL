#include <iostream>
#include <memory.h>
#include <list.h>
#include <set.h>

#include <string>

using namespace std;

int main()
{

    mstd::Set<int> set;


    set.insert(5);

    set.insert(7);

    set.insert(2);

    set.insert(3);

    set.insert(3);

    set.insert(9);
    
    mstd::List ls( set.get_list() );

    std::cout << ls[0] << ":" << ls[1] << ":" << ls[2] << ":" << ls[3] << ":" << ls[4];

    set.erase(2);

    ls = set.get_list();

    std::cout << "\n" << ls[0] << ":" << ls[1] << ":" << ls[2] << ":" << ls[3] << ":" << ls[4];


    return 0;
}