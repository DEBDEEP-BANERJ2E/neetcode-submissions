class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> map;
        for(int i : nums){
            if(map.count(i)) return true;
            map.insert(i);
        }
        return false;
    }
};