class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int i : nums){
            map[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap;
        for(auto& pair : map){
            minHeap.push({pair.second, pair.first});
            if(minHeap.size()>k) minHeap.pop();
        }

        for(int i=0; i<k; i++){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
