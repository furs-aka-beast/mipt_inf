#include <string>
#include <sstream>
#include <exception>

class bad_from_string: public std::exception{
    std::string m_msg;
    public:
    bad_from_string(std::string msg):m_msg(msg){}
    const char* what() const noexcept override{
        return m_msg.c_str();
    }
    virtual ~bad_from_string();
};

template <typename T>
T from_string(std::string const& str){
    std::istringstream s(str);
    s<<std::noskipws;
    while()

}