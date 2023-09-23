#include <iostream>

template <typename T>
bool greater(T a,T b){
    return a>b;
};
template <typename T>
bool less(T a,T b){
    return !(a>b);
};
template <typename T>
T max(T a,T b){
    if(greater <T> (a,b)) return a;
    else return b;
};
template <typename T>
T min(T a,T b){
    if(less <T> (a,b)) return a;
    else return b;
};

int main() {
  int a,b;
  std::cin>>a>>b;
  std::cout<< max <int> (a,b);
}