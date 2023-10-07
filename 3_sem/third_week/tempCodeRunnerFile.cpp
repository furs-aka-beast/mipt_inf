struct IntStackWithMax: IntAbstractQueue{
    IntStack data;
    void push(int x) override {
        data.push(x);
    }
    int pop() override {
        return data.pop();
    }
    int peek() const override {
        return data.peek();
    }
    bool is_empty() const override {
        return data.is_empty();
    }
    bool is_full() const override {
        return data.is_full();
    }
    int get_max() const {
        IntStack copy=data;
        int m=copy.pop();
        while(!copy.is_empty()){
            if (m<copy.peek()) m=copy.pop();
        }
        return m;
    }
};