#include <iostream>
#include "DoubleVectorQueue.h"
//#include "LinkArr.h"
//#include "CircBuff.h"

using i64=int64_t;

int main()
{
    Queue a{};
    a.PushBack(5);
    a.PushBack(4);
    a.PopFront();
    for(i64 i=0; i<a.Size();i++)
    {
    std::cout<<a[i]<<' ';
    }
    std::cout<<a.Size()<<' '<<std::endl;
    return 0;
}
