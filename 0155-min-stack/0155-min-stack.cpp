class MinStack {
public:
    stack<pair<int,int>> st ;
    MinStack() {
        
    }
    
    void push(int val) {
        int x1 = INT_MAX;
        if(!st.empty())
        {
             x1  = st.top().second ;
        }
        x1 = min(x1 , val);
        st.push({val , x1});
    }
    
    void pop() {
        if(!st.empty())
             st.pop() ;
    }
    
    int top() {
        return st.top().first ;
    }
    
    int getMin() {
        return st.top().second ;
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