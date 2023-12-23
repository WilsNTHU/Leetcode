class MyCircularQueue {
public:
    
    MyCircularQueue(int k) {
        queue.reserve(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(head==-1 && tail==-1){
            head = tail = 0;
            queue[tail] = value;
            return true;
        }
        else if((tail+1)%size == head) return false;
        else{
            tail = (tail+1)%size;
            queue[tail] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(head==-1 && tail==-1) return false;
        else if(head == tail){
            head = tail = -1;
            return true;
        }
        else{
            head = (head+1) % size;
            return true;
        }
    }
    
    int Front() {
        if(!isEmpty()) return queue[head];
        else return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return queue[tail];
        else return -1;
    }
    
    bool isEmpty() {
        return (head==-1 && tail==-1);
    }
    
    bool isFull() {
        return ((tail+1)%size == head);
    }
    
private:
    vector<int> queue;
    int head;
    int tail;
    int size;
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