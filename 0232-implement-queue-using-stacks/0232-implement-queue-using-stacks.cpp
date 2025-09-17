class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty()) st.push(x);
        else{
            while(!st.empty()){
                helper.push(st.top()); st.pop();
            }
            st.push(x);
            while(!helper.empty()){
                st.push(helper.top()); helper.pop();
            }
        }
    }
    
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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