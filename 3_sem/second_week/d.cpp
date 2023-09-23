#include <cstdint>
#include <iostream>
struct Cls {
    Cls(char c, double d, std::int32_t i)
        : m_c(c)
        , m_d(d)
        , m_i(i)
    {}
private:
    char m_c;
    double m_d;
    std::int32_t m_i;
};
// Эта функция должна предоставить доступ к полю m_c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т.е.
// доступ предоставляется на чтение и запись.
char& get_c(Cls& cls) {
    Cls* begin=&cls;
    return *(reinterpret_cast <char*> (begin));
}

// Эта функция должна предоставить доступ к полю m_d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т.е.
// доступ предоставляется на чтение и запись.
double& get_d(Cls& cls) {
    auto begin=&get_c(cls);
    begin=begin+8;
    return *(reinterpret_cast <double*> (begin));
}

// Эта функция должна предоставить доступ к полю m_i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т.е.
// доступ предоставляется на чтение и запись.
int& get_i(Cls& cls) {
    auto begin=&get_d(cls);
    begin=begin+1;
    return *(reinterpret_cast <std::int32_t*> (begin));
}

int main (){
    Cls a('a', 22.5, 3);
    std::cout<<get_i(a);
}
