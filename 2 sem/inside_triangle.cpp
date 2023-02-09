#include <iostream>
#include <iomanip>

using i32 = int32_t;

bool chk(i32 x1, i32 y1, i32 x2, i32 y2, i32 x0, i32 y0, i32 x3, i32 y3)
{
    int p0=(x0-x1)*(y2-y1)-(x2-x1)*(y0-y1);
    int p3=(x3-x1)*(y2-y1)-(x2-x1)*(y3-y1);
    if (p0*p3 >= 0)
        return 1;
    else
        return 0;
}

int main()
{
    std::cout<<std::boolalpha;
    i32 x[4], y[4], x0, y0;
    std::cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[0] >> y[0];
    bool ans = chk(x[1], y[1], x[2], y[2], x[0], y[0], x[3], y[3])*chk(x[2], y[2], x[3], y[3], x[0], y[0], x[1], y[1])*chk(x[3], y[3], x[1], y[1], x[0], y[0], x[2], y[2]);;
    std::cout<<ans;
}