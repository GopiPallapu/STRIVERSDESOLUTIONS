class CustomStack {
public:
    vector<int> arr ;
    int size ;
    CustomStack(int maxSize) {
       size = maxSize ;
    }
    
    void push(int x) {
        if(arr.size() < size)
        {
            arr.push_back(x);
        }
    }
    
    int pop() {
        if(arr.size() == 0)
        {
            return -1;
        }
        else
        {
            int val = arr.back() ;
            arr.pop_back() ;
            return val;
        }
    }
    
    void increment(int k, int val) {
      int x = k ;
      if(arr.size() < k)
      {
          x = arr.size() ;
      }
      for(int i =0 ;i<x ; i++)
      {
          arr[i] +=val ;
      }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */