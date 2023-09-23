#include <iostream>

template <typename U, typename T>
void copy_n(T* target, U* source, int n){
    for(int i=0; i<n; i++){
        target[i]=static_cast <T> (source[i]);
    }
}
int main(){
    int ints[] = {1, 2, 3, 4};
double doubles[4] = {};
copy_n(doubles, ints, 4);
std::cout<<typeid(ints[1]).name();
}
