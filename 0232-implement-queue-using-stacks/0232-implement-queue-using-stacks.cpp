class MyQueue {
public:
stack<int> st;
stack<int> gt;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        //remove at bottom
        while(st.size()>0)
        {
            gt.push(st.top());
            st.pop();
        }
        int x=gt.top();
        gt.pop();
        while(gt.size()>0)
        {
            st.push(gt.top());
            gt.pop();
        }
        return x;
    }
    
    int peek() {
         //retreive at bottom
        while(st.size()>0)
        {
            gt.push(st.top());
            st.pop();
        }
        int x=gt.top();
        while(gt.size()>0)
        {
            st.push(gt.top());
            gt.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size()==0) return true;
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