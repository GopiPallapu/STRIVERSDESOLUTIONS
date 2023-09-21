class MyCircularQueue {
public:
    int front ; // front pointer for popping
    int rear ; // rear pointer for pushing
    vector<int>qu ; // array
    int size ; // max size
    int currentSize ; // current size

    // initialization
    MyCircularQueue(int k) {
        size = k ;
        qu.resize(size, -1 ) ;
        front = -1 ;
        rear = -1;
        currentSize = 0;
    }
    // push operation
    bool enQueue(int value) {
        // over flow condition
        if(currentSize == size)
        {
            return false;
        }
        // queue empty
        if(front == -1 && rear == -1)
        {
            front = 0 ;
            rear  = 0 ;
        }
        else
        {
            rear = (rear +1 )%size ; // increment the rear // special case mod for circular queue
        }
        qu[rear] = value ; // push
        currentSize += 1 ; // increment size
        return true ;
    }
    // pop operation
    bool deQueue() {
        // queue empty
        if(currentSize == 0)
        {
            return false;
        }
        else
        {
            front = (front + 1)%size ; // increment the front // special case mod for circular queue
        }
        currentSize -=1 ; // decrement size
        return true ;
    }
    
    int Front() {
        if(currentSize == 0)
        {
            return -1;
        }
        else
        {
            return qu[front] ;
        }
    }
    
    int Rear() {
       if(currentSize == 0)
        {
            return -1;
        }
        else
        {
            return qu[rear] ;
        }
    }
    
    bool isEmpty() {
        if(currentSize == 0)
        return true ;
        else
            return false ;
    }
    
    bool isFull() {
        if(currentSize == size)
        {
            return true ;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */