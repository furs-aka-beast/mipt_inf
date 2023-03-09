#include <iostream>

using i64=int64_t;

class Vector{
public: 
void PushBack (i64 el){
    if(reserved_<=size_)
    {
        ReAlloc_(2*size_);
    }
    *(data_+size_)=el;
    size_++;
}
void PopBack () { 
    if(Size()>0) size_--;
}
Vector () {
    size_=0;
    data_=nullptr;
    ReAlloc_(default_size_);
}
Vector (i64 size){
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
    return *(data_+num);
}

i64* begin(){return data_;}
i64* end(){return data_+size_;}
private:
void ReAlloc_(i64 new_size){
    i64 * new_data = new i64[new_size];
    for (i64 i=0;i<size_;i++)
    {
        *(new_data+i)=*(data_+i);
    }
    delete[] data_;
    data_=new_data;
    reserved_=new_size;
}
i64* data_;
i64 size_, reserved_;
i64 default_size_=2;




};

