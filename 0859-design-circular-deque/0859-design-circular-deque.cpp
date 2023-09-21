class MyCircularDeque {
public:
    int front ; // front pointer for popping
    int rear ; // rear pointer for pushing
    vector<int>qu ; // array
    int size ; // max size
    int currentSize ; // current size

    // initialization
    MyCircularDeque(int k) {
        size = k ;
        qu.resize(size, -1 ) ;
        front = -1 ;
        rear = -1;
        currentSize = 0;
    }
    // push operation on front 
    bool insertFront(int value) {
        // overflow case
        if(currentSize == size)
        {
            return false;
        }
        if(front == -1 && rear == -1 )
        {
            front = 0 ;
            rear = 0;
        }
        else if(front == 0)
        {
            front = size -1 ;
        }
        else
        {
            front --;
        }
        qu[front] = value ;
        currentSize += 1 ;
        return true;
    }
    //push operation on rear
    bool insertLast(int value) {
        // overflow case
        if(currentSize == size)
        {
            return false;
        }
        if(rear == -1 && front == -1)
        {
            rear = 0 ;
            front = 0;
        }
        else if(rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear = ( rear + 1)% size ;
        }
        qu[rear] = value ;
        currentSize += 1 ;
        return true;
    }
    // pop operation on front
    bool deleteFront() {
        // underflow case
        if(currentSize == 0)
        {
            return false;
        }
        else if(front == rear)
        {
            front = -1 ;
            rear  = -1 ;
        }
        else if( front == size -1)
        {
            front = 0;
        }
        else
        {
            front = (front+1)%size ;
        }
        currentSize -=1 ;
        return true;
    }
    // pop operation on rear
    bool deleteLast() {
         // underflow case
        if(currentSize == 0)
        {
            return false;
        }
        else if(front == rear)
        {
            front = -1 ;
            rear  = -1 ;
        }
        else if( rear == 0)
        {
            rear = size -1 ;
        }
        else
        {
            rear = rear -1 ;
        }
        currentSize -=1 ;
        return true;
    }
    
    int getFront() {
        // base case
        if(currentSize == 0)
        {
            return -1;
        }
        else
        {
            return qu[front] ;
        }
    }
    
    int getRear() {
         // base case
        if(currentSize == 0)
        {
            return -1;
        }
        else
        {
            return qu[rear] ;
        }
    }
    // underflow case
    bool isEmpty() {
        if(currentSize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // overflow case
    bool isFull() {
         if(currentSize == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */