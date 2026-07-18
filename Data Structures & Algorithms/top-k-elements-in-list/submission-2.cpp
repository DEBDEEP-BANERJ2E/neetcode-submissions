class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        vector<vector<int>> bucket(n+1);
        unordered_map<int, int> count;

        for(int i : nums){
            count[i]++;
        }

        for(auto& pair : count){
            int num = pair.first;
            int freq = pair.second;
            bucket[freq].push_back(num);
        }

        for(int i=n; i>0; i--){
            for(int j : bucket[i]){
                res.push_back(j);
                if(res.size()==k) return res;
            }
        }
    }
};
