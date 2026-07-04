class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int index = 0;
        for(auto i : nums) {
            if(mp.count(target - i)) 
                return {mp[target - i], index};
            mp[i] = index++; 
        }
        return {};
    }
};