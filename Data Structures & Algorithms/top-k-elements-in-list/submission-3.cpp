class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // Max-heap storing pairs of {frequency, element}
        priority_queue<pair<int, int>> maxHeap;
        for (auto& pair : count) {
            maxHeap.push({pair.second, pair.first});
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
