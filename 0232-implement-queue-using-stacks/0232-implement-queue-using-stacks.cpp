class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int size;
    int start,end;
    MyQueue() {
        size=0;
        start=-1;
        end=-1;
    }
    
    void push(int x) {
        st1.push(x);
        size++; 
    }
    
    int pop() {
        if(!st2.empty()){
            int ele = st2.top();
            size--;
            st2.pop();
            return ele;
        }
        else{
            for(int i=1;i<=size;i++){
                st2.push(st1.top());
                st1.pop();
            }
            int ele = st2.top();
            size--;
            st2.pop();
            return ele;
        }
    }
    
    int peek() {
        if(!st2.empty()) return st2.top();
        else{
            for(int i=1;i<=size;i++){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(size==0) return true;
        else return false;
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