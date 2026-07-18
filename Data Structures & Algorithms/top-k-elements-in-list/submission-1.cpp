class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums)
            count[num]++;
        // Min-heap storing pairs of {frequency, element}
        // min-heap keeps the smallest frequency at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap;

        for (auto& pair : count) {
            minHeap.push({pair.second, pair.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the element with the least frequency
            }
        }

        // Extract elements from the heap
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};
