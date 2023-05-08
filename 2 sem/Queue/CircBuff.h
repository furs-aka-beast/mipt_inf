#include <iostream>

using i64=int64_t;

class Queue{
public: 
void PushBack (i64 el){
    if(reserved_<=size_)
    {
        ReAlloc_(2*size_);
    }
    *(data_+(size_+begin_)%reserved_)=el;
    size_++;
}
void PopBack () { 
    if(Size()>0) size_--;
}
void PopFront() {
    size_--;
    begin_++;
    BeginCheck();
}
Queue () {
    size_=0;
    data_=nullptr;
    ReAlloc_(default_size_);
}
Queue (i64 size){
    size_=size;
    data_=nullptr;
    ReAlloc_(size_*2);
    for (i64 i=0;i<size_;i++ ){*(data_+i)=0;}

} 
i64 Size() const {
    return size_;
 }
i64& operator[](i64 num)
{
    if ((num+begin_)<reserved_){
            return *(data_+num+begin_);
        }
        else{
            return *(data_+(num+begin_-reserved_));
        }
}

private:
void ReAlloc_(i64 new_size){
    i64 * new_data = new i64[new_size];
    for (i64 i=0;i<size_;i++)
    {
        if ((i+begin_)<reserved_){
            *(new_data+i)=*(data_+i+begin_);
        }
        else{
            *(new_data+i)=*(data_+(i+begin_-reserved_));
        }
        
    }
    delete[] data_;
    data_=new_data;
    reserved_=new_size;
    begin_=0;
}
void BeginCheck(){
    if(begin_>=reserved_){
        begin_=begin_-reserved_;
    }
}
i64* data_;
i64 begin_, size_, reserved_;
i64 default_size_=2;




};