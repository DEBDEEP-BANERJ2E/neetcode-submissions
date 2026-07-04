class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);
        int c=0, prev;
        for(int i : temperatures){
            while(!st.empty() && i > temperatures[st.top()]){
                prev= st.top();
                st.pop();
                res[prev] = c - prev;
            }
            st.push(c);
            c++;
        }
        return res;
    }
};
