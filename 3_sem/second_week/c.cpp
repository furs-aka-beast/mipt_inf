#include <string>
#include <iostream>
struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const std::string& msg) : msg(msg) { }
private:
    const std::string& msg;
};
void foo_says(const Foo& foo) { foo.say(); }

struct Steal: Foo {
    Steal(const std::string& msg) : Foo(msg) {}
};
Steal get_foo(const std::string& msg){
    return Steal(msg);
}

int main(){
    std::string a="aaaa";
    foo_says(get_foo("msg"));
}