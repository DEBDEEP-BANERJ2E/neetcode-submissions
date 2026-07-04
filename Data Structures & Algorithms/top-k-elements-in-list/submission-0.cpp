class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

        for(int i : nums){
            m[i]++;
        }

        for(auto const& [num, freq] : m){
            p.push({freq, num});
            if(p.size()>k) p.pop();
        }

        vector<int> output;

        while(p.size()>0){
            output.push_back(p.top().second);
            p.pop();
        }
        return output;
    }
};