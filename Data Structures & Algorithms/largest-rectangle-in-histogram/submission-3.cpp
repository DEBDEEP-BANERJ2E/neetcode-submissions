class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // Stack stores pairs of {index, height}
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            // Maintain strictly increasing order in the stack
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                // Calculate area for the popped bar
                int width = i - index;
                maxArea = max(maxArea, height * width);
    // The current bar can extend backwards to the popped bar's start index
                start = index;
            }
            st.push({start, heights[i]});
        }
        int n = heights.size();// Clear out any remaining bars left in the stack
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            // These bars can extend all the way to the end of the histogram
            int width = n - index;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};
