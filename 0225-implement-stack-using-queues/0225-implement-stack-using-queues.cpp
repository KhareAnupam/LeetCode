class MyStack {
public:
    queue<int> q1;
    // queue<int> q2;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        if(size==0){
            q1.push(x);
            size++;
        }
        else{
            q1.push(x);
            size++;
            for(int i=1;i<size;i++){
                q1.push(q1.front());
                q1.pop();
            }
        }
        
    }
    
    int pop() {
        int ele = q1.front();
        q1.pop();
        size--;
        return ele;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(size==0) return true;
        else return false;
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