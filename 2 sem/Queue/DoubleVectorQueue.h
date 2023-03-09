#include <iostream>
#include "Vector.h"

using i64=int64_t;

class Queue{
    public:
    void PushBack(i64 item){tail.PushBack(item);}
    void PopFront(){
        if(head.Size()==0)
        {
            for(i64 i = tail.Size()-1; i >=0 ; i--)
            {
                head.PushBack(tail[i]);
                tail.PopBack();
            }
        }
        head.PopBack();
    }
    i64 Size(){return head.Size()+tail.Size();}
    i64& operator[](i64 num){
        if(num<head.Size())
        {
            return head[head.Size()-num-1];
        }
        else return tail[num-head.Size()];

    }
    Queue(): head(), tail(){}
    Queue(i64 num): head(), tail(){
        for (i64 i = 0; i < num; i++)
        {
            head.PushBack(0);
        }
        
    }


    private:
    Vector head{};
    Vector tail{};
};