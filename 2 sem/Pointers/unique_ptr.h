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
    ~SmartPtr(){
        delete(ptr);
    }
    private:
    T * ptr;

};