#include <iostream>
struct Shout{
    Shout(int i): id(i){}
    ~Shout() { std::cout <<  id << "|"; }
    int id;
};



int main() {
    std::shared_ptr u = std::make_shared<Shout>(1); // INIT

    std::shared_ptr<Shout> p(u);                    // MOVE

    return 0;



}