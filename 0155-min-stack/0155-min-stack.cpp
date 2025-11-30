class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if(val >= mini) {
                st.push(val);
            } else {
                // encode value
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long x = st.top();
        st.pop();
        
        if(x < mini) {
            // encoded value detected — restore previous min
            mini = 2LL * mini - x;
        }
        
        if(st.empty()) {
            // reset mini for future pushes
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        long long x = st.top();
        
        if(x < mini) {
            // encoded — real top is mini
            return mini;
        } else {
            return x;
        }
    }
    
    int getMin() {
        return mini;
    }
};
