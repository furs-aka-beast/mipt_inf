#include <iostream>
template <int a, int b>
struct pew{
    static const int ref=a* pew<a,b-1>::ref;
};

template <int a>
struct pew <a, 0>{
    static const int ref=1;
};
template <int a, int del=a-1>
struct is_prime{
    static const bool ans= ((a%del)!=0 and is_prime<a,del-1>::ans);  
};
template <int a>
struct is_prime<a,1>{
    static const bool ans= 1;
};
int main(){
    int a;
    std::cout<<is_prime<6>::ans;
    std::cout<<pew<2,3>::ref;
}