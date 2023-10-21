#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
    using namespace std::chrono_literals;
    
int main(){
    int cnt=0;
    std::string str="";
    while(cnt<=100){
        if(cnt/10>str.size()) str+='#';
        std::cout<<'\r'<<'['<<std::setfill('.')<<std::setw(10)<<std::left;
        std::cout<<str;
        std::cout<<']'<<std::setfill(' ')<<std::setw(4)<< std::right<<cnt<<'%'<<std::flush;
        cnt+=3;
        std::this_thread::sleep_for(100ms);
    }
}