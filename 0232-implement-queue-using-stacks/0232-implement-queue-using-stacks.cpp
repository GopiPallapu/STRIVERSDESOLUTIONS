class MyQueue {
public:
    stack<int> st1 , st2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        // push x to st1
        st1.push(x) ;
    }
    
    int pop() {
        while(!st1.empty()) // push all elements to st2
        {
            st2.push(st1.top());
            st1.pop();
        }
        int val = st2.top() ; // take top from st2
        st2.pop() ;
        while(!st2.empty()) // push all elements to st1
        {
            st1.push(st2.top());
            st2.pop() ;
        }
        return val;
    }
    
    int peek() {
         while(!st1.empty()) // push all elements to st2
        {
            st2.push(st1.top());
            st1.pop();
        }
        int val = st2.top() ; // take top from st2
        while(!st2.empty()) // push all elements to st1
        {
            st1.push(st2.top());
            st2.pop() ;
        }
        return val;
    }
    
    bool empty() {
        return st1.empty() ; // check empty or not
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */