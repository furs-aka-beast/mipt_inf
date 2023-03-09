#pragma once

#include <cstdint>

using i64=int64_t;

struct ListItem
{
    int64_t data;
    ListItem *prev, *next;
};

class Queue
{
    public:
    void PushBack(int64_t data){
        if(tail!=nullptr){
            ListItem *new_item=new ListItem;
            (*new_item).data=data;
            (*new_item).prev=tail;
            (*new_item).next=nullptr;
            (*tail).next=new_item;
            tail=new_item;
        }
        else{
            ListItem *new_item=new ListItem;
            (*new_item).data=data;
            (*new_item).prev=nullptr;
            (*new_item).next=nullptr;
            head=new_item;
            tail=new_item;
            //std::cout<<head->data<<' ';
        }
    }
    void PopFront(){
        if(Size()>1){
        head=(*head).next;
        (*head).prev=nullptr;
        }
        else{
            head=nullptr;
            tail=nullptr;
        } 
    } 
    i64& operator[](i64 num){
        ListItem* x=head;
        for(i64 i=0;i<num;i++){
            x=(*x).next;
        }
        return (*x).data;
}
    i64 Size(){
        if(head!=nullptr){
        i64 cnt=1;
        for(auto i=head;(*i).next!=nullptr;i=(*i).next){cnt++;}
        return cnt;
        }
        else return 0;
    }
    Queue(){
        head=nullptr;
        tail=nullptr;
        
    }
    Queue(i64 size){
        head=nullptr;
        tail=nullptr;
    while(size>0)
    {
        PushBack(0);
        size--;
    }
    }
    private:
    ListItem *head, *tail;
};


