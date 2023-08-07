class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minLog.empty()){
            minLog.push(val);
        }
        else if (minLog.top() <= val){
            minLog.push(minLog.top());
        } else {
            minLog.push(val);
        }
        mystack.push(val);
    }
    
    void pop() {   
        minLog.pop();
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return minLog.top();
    }

    private:
        stack<int> mystack;
        stack<int> minLog;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */