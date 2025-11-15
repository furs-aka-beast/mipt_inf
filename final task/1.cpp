#include <iostream>

struct HaHa{
    int a,b;
};
std::ostream& operator << (std::ostream &os, const HaHa &haha)
{
    return os << haha.a << " " << haha.b;
}
std::istream& operator >> (std::istream &is, HaHa &haha)
{
    is>>haha.a>>haha.b;
    return is;
}
int main(){
    HaHa haha;
    std::cin>>haha;
    std::cout<<haha;
}