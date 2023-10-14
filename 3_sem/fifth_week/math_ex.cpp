#include <exception>
#include <string>
#include <iostream>

class math_ex: public std::exception{
    std::string m_msg;
    public:
    math_ex(std::string msg):m_msg(msg){}
    const char* what() const noexcept override{
        return m_msg.c_str();
    }
};
int main(){
    try{
        throw math_ex("LoL");
    }
    catch(math_ex ex){
        std::cout<<ex.what();
    }
}
