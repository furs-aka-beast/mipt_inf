#pragma once

#include <cstdint>

using i64=int64_t;

struct ListItem
{
    int64_t data;
    ListItem *prev, *next;
};

class List
{
    public:
    void PushBack(int64_t data){
        if(tail!=nullptr){
            ListItem *new_item;
            (*new_item).data=data;
            (*new_item).prev=head;
            (*new_item).next=nullptr;
        }
        else{
            ListItem *new_item;
            (*new_item).data=data;
            (*new_item).prev=nullptr;
            (*new_item).next=nullptr;
            head=new_item;
            tail=new_item;
        }
    }
    void PopFront(){
        (*(*head).next).prev=nullptr;
    } 
    i64& operator[](i64 num){
        ListItem* x=head;
        for(i64 i=0;i<num;i++){
            x=(*x).next;
        }
        return (*x).data;
}
    i64 Size(){
        i64 cnt=0;
        for(auto i=head;(*head).next!=nullptr;i++){cnt++;}
        return cnt;
    }
    List(){
        head=nullptr;
        tail=nullptr;
        
    }
    List(i64 size){
        head=nullptr;
        tail=nullptr;
    while(size>0)
    {
        PushBack(0);
    }
    }
    private:
    ListItem *head, *tail;
};


