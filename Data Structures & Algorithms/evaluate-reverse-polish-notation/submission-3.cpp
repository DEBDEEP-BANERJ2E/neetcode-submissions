class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the second operand first
                int b = st.top(); st.pop();
                // Pop the first operand second
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                // Truncates toward zero automatically in C++
                else if (token == "/") st.push(a / b); 
            } else {
                // Token is a number, convert string to integer and push
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
