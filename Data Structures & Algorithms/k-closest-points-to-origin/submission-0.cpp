class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap storing pairs of {squared_distance, point_index}
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x * x + y * y;
            
            maxHeap.push({distance, i});
            
            // Maintain heap size to exactly k elements
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Extract the k closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(points[index]);
        }
        
        return result;
    }
};
