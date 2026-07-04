class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        stack<int> s;
        int max_ar = 0;
        int h, w;

        for (int i = 0; i <= heights.size(); i++) {
            int current_height = (i == heights.size()) ? 0 : heights[i];

            while (!s.empty() && heights[s.top()] >= current_height) {
                h = heights[s.top()];
                s.pop();
                w = s.empty() ? i : i - s.top() - 1;
                
                max_ar = max(max_ar, h * w);
            }
            s.push(i);
        }
        return max_ar;
    }
};