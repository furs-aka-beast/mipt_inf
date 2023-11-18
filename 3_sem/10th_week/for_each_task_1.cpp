#include <algorithm>
#include <iostream>

int main(){
    std::string s;
    std::cin>>s;
    auto l=[shift=3](char &ch){
        if(ch>'Z') ch-='a'-'A';
        ch+=shift%('Z'-'A'+1);
        if(ch>'Z') ch-='Z'-'A'+1;
    };
    std::for_each(s.begin(), s.end(),l);
    std::cout<<s;
}