#include <iostream>
#include <memory.h>

using namespace mstd;

int main()
{

    mstd::shared_ptr<int> a(new int(4));

    mstd::shared_ptr<int> b(new int(5));

    b.swap(a);

    std::cout << *a << ":" << *b;

    return 0;
}