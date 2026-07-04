class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b;
        for(string c : tokens){
            if(c == "+" || c == "-" || c== "*" || c == "/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                if(c == "+") st.push(a+b);
                if(c == "-") st.push(b-a);
                if(c == "*") st.push(a*b);
                if(c == "/") st.push(b/a);
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
