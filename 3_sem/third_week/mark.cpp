struct IntAbstractQueue {
    virtual void push(int x) = 0;
    virtual int pop() = 0;
    virtual int peek() const = 0;
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;

    virtual ~IntAbstractQueue() { }
};
struct IntStack: IntAbstractQueue {
    void push(int x) override {
        data[top++] = x;
    }
    int pop() override {
        return data[--top];
    }
    bool is_empty() const override {
        return 0 == top;
    }
    bool is_full() const override {
        return 10 == top;
    }
private:
    unsigned top = 0;
    int data[10];
};

struct IntStackWithMax: IntStack{
    
    int get_max() const {
        IntStack copy(*this);
        int m=copy.pop();
        while(!copy.is_empty()){
            int t=copy.pop();
            if (m<t) m=t;
        }
        return m;
    }
};

#include <cassert>
void with_queue_do(IntAbstractQueue &q) {
    assert(q.is_empty());
    q.push(1);
    assert(!q.is_empty());
    assert(1 == q.peek());
    assert(!q.is_empty());
    assert(1 == q.pop());
    assert(q.is_empty());
    for (int cnt = 0; cnt != 10; ++cnt)
        q.push(cnt);
    assert(q.is_full());
}
void with_stackwithmax_do(IntStackWithMax &swm) {
    with_queue_do(swm);
    for (int cnt = 10; cnt != 0; --cnt)
        assert(cnt - 1 == swm.get_max() and cnt - 1 == swm.pop());
    assert(swm.is_empty()); 
}

int main() {
    IntStackWithMax swm;
    with_stackwithmax_do(swm);
    return 0;
}
