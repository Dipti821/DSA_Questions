class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        //TC: O(N) SC: O(N)+O(N)
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);
        
        // using only one queue
        // TC: O(N) ,SC:O(N)
        q1.push(x);
        int k=q1.size();
        k--;
        while(k--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int k=q1.front();
        q1.pop();
        return k;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */