class MinStack {
    stack<int>s;
    int mi=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(val<=mi)
            s.push(mi) ,mi=val;
       s.push(val); 
    }
    
    void pop() {
        if(s.top()==mi){
            s.pop();
            mi=s.top();
        }
        s.pop();
    }
    
    int top() {
       return s.top(); 
    }
    
    int getMin() {
       return mi; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */