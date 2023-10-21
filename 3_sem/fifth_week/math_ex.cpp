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
    virtual ~math_ex();
};
int main(){
    throw math_ex("LoL");
}
