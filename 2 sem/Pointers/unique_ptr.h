#pragma once

template <class T> class SmartPtr{
    public:
    SmartPtr() : ptr(nullptr){}
    SmartPtr(T * raw_ptr) : ptr(raw_ptr){}
    T& operator*(){
        return *ptr;
    }
    T* operator->() {
        return ptr;
    }
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator= (const SmartPtr&) = delete;
    SmartPtr& operator= (SmartPtr&& p) {
        if(this != &p){
            Move(p);
        }
        return *this;
    };
    SmartPtr(SmartPtr&& p){
        Move(p);
    }
    ~SmartPtr(){
        delete(ptr);
    }
    private:
    T * ptr;
    void Move(SmartPtr &p){
        ptr=p.ptr;
        p.ptr=nullptr;
    }

};