#include <iostream>
#include <vector>

using i32 = int32_t;

int main()
{
    std::vector<i32> prost = {1};
    for (i32 i = 2; i <= 1000; i++)
    {
        bool flag = 1;
        for (i32 j = 1; j < prost.size(); j++)
        {
            if (i % prost[j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            prost.push_back(i);
    }
    for (i32 j = 0; j < prost.size(); j++)
    {
        std::cout << prost[j] << ' ';
    }
}