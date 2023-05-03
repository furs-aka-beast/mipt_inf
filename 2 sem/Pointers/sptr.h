#include <cstddef>
#include <iostream>
template <class T>
class UniquePtr{
    public:
    UniquePtr() : ptr(nullptr){}
    UniquePtr(T * raw_ptr) : ptr(raw_ptr){}
    T& operator*(){
        return *ptr;
    }
    T* operator->() {
        return ptr;
    }
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator= (const UniquePtr&) = delete;
    UniquePtr& operator= (UniquePtr&& p) {
        if(this != &p){
            Move(p);
        }
        return *this;
    };
    UniquePtr(UniquePtr&& p){
        Move(p);
    }
    ~UniquePtr(){
        delete(ptr);
    }
    private:
    T * ptr;
    void Move(UniquePtr &p){
        ptr=p.ptr;
        p.ptr=nullptr;
    }

};


// ================================================
struct RefCntBlock {
    size_t strong, weak;
};

template <class T>
class WeakPtr;

template <class T>
class SharedPtr {   
    friend class WeakPtr<T>;
public:
    SharedPtr() {  
        std::cout<<"created";
        ptr = nullptr;
        cnt = nullptr;
    }
    SharedPtr(const SharedPtr& o) {  
        Copy(o);
    }
    SharedPtr& operator=(const SharedPtr& o) {  
        Clear();
        Copy(o);
        return *this;
    }
    
    SharedPtr(SharedPtr&& o) { 
        Move(o);
    }
    
    SharedPtr& operator=(SharedPtr&& o) { 
        Clear();
        Move(o);
        return *this;
    }
    
    SharedPtr(T* p) {  
        ptr=p;
        cnt = new RefCntBlock;
        cnt->strong = 1;
        cnt->weak = 0;
    }
    
    // Implementation below
    SharedPtr(const WeakPtr<T>& o);
    
    // Replaces pointer with nullptr
    void Reset() {
        Clear();
    }
    
    T* operator->() {  
        return ptr;
    }
    
    T& operator*() {  
        return *ptr;
    }
    
    ~SharedPtr () {  
        Clear();
    }
    
private:
    T* ptr;
    RefCntBlock* cnt;
    void Move(SharedPtr& p){
        Copy(p);
        p.Clear();
    }
    void Copy(const SharedPtr& p){
        this->ptr=p.ptr;
        this->cnt=p.cnt;
        	if (this->cnt != nullptr){
    	    this->cnt->strong++;	
    	}
    }
    void Clear(){
        if(cnt!=nullptr){
            cnt->strong--;
            if(cnt->strong == 0 && ptr!=nullptr){
                delete ptr;
            }
            if(cnt->weak == 0 && cnt->strong == 0){
                delete cnt;
            }
            ptr=nullptr;
            cnt=nullptr;
        }
    }
};

template <class T>
class WeakPtr {
    friend class SharedPtr<T>;
public:
    WeakPtr() {         
        ptr = nullptr;
        cnt = nullptr;
    }
    WeakPtr(const WeakPtr& o) {
        Copy(o);
    }
    WeakPtr& operator=(const WeakPtr& o) {  
        Clear();
        Copy(o);
        return *this;
    }
    
    WeakPtr(WeakPtr&& o) {
        Move(o);
    }
    
    WeakPtr& operator=(WeakPtr&& o) {
        Clear();
        Move(o);
        return *this;
    }
    
    WeakPtr(const SharedPtr<T>& o) {
        Copy(o);
    }
    
    WeakPtr& operator=(const SharedPtr<T>& o) {
        Clear();
        Copy(o);
        return *this;
    }
    
    // Replaces pointer with nullptr
    void Reset() {
        Clear();
    }
    
    bool Expired() const {
        return cnt == nullptr || cnt->strong == 0;
    }
    
    SharedPtr<T> Lock() { 
        SharedPtr <T> p;
        p.ptr=ptr;
        p.cnt=cnt;
        if(cnt != nullptr){
            cnt->strong++;
        }
        return p;
    }
        
    ~WeakPtr () {
        Clear();
    }
    
private:
    T* ptr;
    RefCntBlock* cnt;
    void Move(WeakPtr& p){
        Copy(p);
        p.cnt=nullptr;
        p.cnt=nullptr;
        this->cnt->weak--;
    }
    void Copy(const WeakPtr& p){
        this->ptr=p.ptr;
        this->cnt=p.cnt;
        if (this->cnt != nullptr){
    	    this->cnt->weak++;	
    	}
    }
    void Move(SharedPtr <T>& p){
        Copy(p);
        p.Clear();
    }
    void Copy(const SharedPtr <T>& p){
        this->ptr=p.ptr;
        this->cnt=p.cnt;
        if (this->cnt != nullptr){
    	    this->cnt->weak++;	
        }
    }
    void Clear(){
        if(cnt!=nullptr){
            cnt->weak--;
            if(cnt->strong == 0 && cnt->weak == 0){
                delete cnt;
            }
            ptr=nullptr;
            cnt=nullptr;
        }   
    }
};

template <class T>
SharedPtr<T>::SharedPtr(const WeakPtr<T>& o) {
        ptr=o.ptr;
        cnt=o.cnt;
        cnt->strong++;
}
