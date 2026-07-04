class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<pair<int, int>> s; 

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!s.empty() && s.top().second > heights[i]) {
                pair<int, int> top = s.top();
                s.pop();
                max_area = max(max_area, top.second * (i - top.first));
                start = top.first;
            }
            s.push({start, heights[i]});
        }
        
        while (!s.empty()) {
            pair<int, int> top = s.top();
            s.pop();
            max_area = max(max_area, top.second * ((int)heights.size() - top.first));
        }

        return max_area;
    }
};