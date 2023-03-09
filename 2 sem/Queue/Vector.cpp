#include <iostream>
#include "Vector.h"

using i64=int64_t;

int main()
{
    Vector a{};
    a.PushBack(5);
    a.PushBack(2);
    a.PushBack(3);
    a.PopBack();
    for(i64 i:a)
    {
    std::cout<<i<<' ';
    }
    std::cout<<a.Size()<<' '<<std::endl;
    return 0;
}
