#include <iostream>
#include <list.h>

using namespace mstd;

int main()
{
    
    List<int> ls;

    //ls.push_front(3);

    ls.push_front(3);
    
    ls.push_front(2);

    ls.push_front(1);

    ls.push_front(0);

    std::cout << "Was: " << ls[0] << ":" << ls[1] << ":" << ls[2] << ":" << ls[3] << ":\n";

    List<int> ls2;

    ls2.push_front(1);

    ls2.push_front(1);

    std::cout << "Stalo: " << ls2[0] << ":" << ls2[1] << ":\n";

    //std::cout << ls[1];
    return 0;
}