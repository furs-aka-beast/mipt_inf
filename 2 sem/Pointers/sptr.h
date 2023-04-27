#include <cstddef>
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
        ptr = nullptr;
        cnt = nullptr;
    }
    SharedPtr(const SharedPtr& o) {  
        Copy(o);
    }
    SharedPtr& operator=(const SharedPtr& o) {  
        delete this;
        Copy(o);
        return *this;
    }
    
    SharedPtr(SharedPtr&& o) { 
        Move(o);
    }
    
    SharedPtr& operator=(SharedPtr&& o) { 
        delete this;
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
        delete this;
    }
    
    T* operator->() {  
        return ptr;
    }
    
    T& operator*() {  
        return *ptr;
    }
    
    ~SharedPtr () {  
        if(cnt!=nullptr){
            cnt->strong--;
            if(cnt->strong == 0){
                delete ptr;
            }
            if(cnt->weak == 0){
                delete cnt;
            }
            ptr=nullptr;
            cnt=nullptr;
        }
    }
    
private:
    T* ptr;
    RefCntBlock* cnt;
    void Move(SharedPtr& p){
        Copy(p);
        delete p;
    }
    void Copy(const SharedPtr& p){
        this->ptr=p->ptr;
        this->counter=p->counter;
        	if (this->counter != nullptr){
    	    this->counter->strong++;	
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
        delete this;
        Copy(o);
        return *this;
    }
    
    WeakPtr(WeakPtr&& o) {
        Move(o);
    }
    
    WeakPtr& operator=(WeakPtr&& o) {
        delete this;
        Move(o);
        return *this;
    }
    
    WeakPtr(const SharedPtr<T>& o) {
        Copy(o);
    }
    
    WeakPtr& operator=(const SharedPtr<T>& o) {
        delete this;
        Copy(o);
        return *this;
    }
    
    // Replaces pointer with nullptr
    void Reset() {
        delete this;
    }
    
    bool Expired() const {
        return cnt == nullptr || cnt->strong == 0;
    }
    
    SharedPtr<T> Lock() { 
        SharedPtr <T> p;
        p->ptr=ptr;
        p->cnt=cnt;
        return p;
    }
        
    ~WeakPtr () {
        if(cnt!=nullptr){
            cnt->weak--;
        if(cnt->strong == 0 && cnt->weak == 0){
                delete cnt;
        }
        ptr=nullptr;
        cnt=nullptr;
        }
    }
    
private:
        T* ptr;
    RefCntBlock* cnt;
    void Move(WeakPtr& p){
        Copy(p);
        delete p;
    }
    void Copy(const WeakPtr& p){
        this.ptr=p.ptr;
        this.counter=p.counter;
        	if (this.counter != nullptr){
    	    this.counter->weak++;	
    	}
    }
    void Move(SharedPtr <T>& p){
        Copy(p);
        delete p;
    }
    void Copy(const SharedPtr <T>& p){
        this->ptr=p.ptr;
        this->counter=p.counter;
        	if (this.counter != nullptr){
    	    this.counter->weak++;	
    	}
    }
};

template <class T>
SharedPtr<T>::SharedPtr(const WeakPtr<T>& o) {
        ptr=o.ptr;
        cnt=o.cnt;
        cnt->strong++;
}
