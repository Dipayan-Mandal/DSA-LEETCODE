class MinStack {
public:
    stack<long long> st;
long long mn=INT_MAX;
    MinStack() {}

    void push(int val) {
        if (st.size() == 0) {
            st.push(val);
            mn = val;
        } else if (val >= mn) st.push(val);
        else
        {
            st.push(2LL * val - mn);
            mn=val;
        }
    }

    void pop() {
        if(st.top()>=mn) st.pop();
        else
        {
            mn=2*mn-st.top();
            st.pop();
        }
    }

    int top() {
         if(st.top()>=mn) return st.top();
         else return mn;
    }

    int getMin() { return mn; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */