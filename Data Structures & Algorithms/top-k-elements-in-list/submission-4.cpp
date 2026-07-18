class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int i : nums){
            map[i]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for(auto& pair : map){
            maxHeap.push({pair.second, pair.first});
        }

        for(int i=0; i<k; i++){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            if(res.size()==k) return res;
        }
    }
};
