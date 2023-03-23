#pragma once

using i64 = int64_t; //тут оператор создания только один раз, дальше можно только копировать (то есть 
                     //одному реальному указателю в действительности соответствует лишь одна структура)
                     // lock: weak -> sheared, weak_ptr - отдельный класс со своим конструктором

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
    private:
    T * ptr;
    i

};