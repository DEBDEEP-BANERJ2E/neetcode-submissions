class MinStack {
private:
    std::stack<int> st;
    std::stack<int> min;

public:
    MinStack() {
    }
    void push(int val) {
        if(st.empty()) min.push(val);
        st.push(val);
        if(val <= min.top()) min.push(val);
    }
    void pop() {
        if(st.top() == min.top()) min.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return min.top();
    }
};
