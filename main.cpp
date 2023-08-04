#include <iostream>
#include <memory>

class Govno
{
public:
    int sw()
    {
        return 1;
    }
};

int main()
{
    std::shared_ptr<int> b(new int(4));

    int *a = b.get();

    int *c = b.get();

    std::cout << b.use_count();
    
}