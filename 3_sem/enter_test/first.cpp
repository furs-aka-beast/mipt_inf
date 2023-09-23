#include <iostream>
#include <stack>

void array_shift(int *begin, int *end, int shift){
    shift=shift%(end-begin);
    std::stack <int> buff;
    for (int i=end-begin-1; i>end-begin-1-shift;i--){
        buff.push(begin[i]);
    }
    for (int i=0; i<end-begin-shift;i++){
        begin[end-begin-i-1]=begin[end-begin-i-shift-1];
    }
    for (int i=0; i<shift;i++){
        begin[i]=buff.top();
        buff.pop();
    }
}

int main(){

}