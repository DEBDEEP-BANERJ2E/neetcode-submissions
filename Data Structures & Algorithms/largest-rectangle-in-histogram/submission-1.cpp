class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        stack<int> s;
        int max_ar = 0;

        for (int i = 0; i <= heights.size(); i++) {
            int current_height = (i == heights.size()) ? 0 : heights[i];

            while (!s.empty() && heights[s.top()] >= current_height) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                
                max_ar = max(max_ar, height * width);
            }
            s.push(i);
        }
        return max_ar;
    }
};