class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> n;
        for(int i=0; i<nums.size(); i++){
            if(n.count(nums[i])) return true;
            n.insert(nums[i]);
        }
        return false;
    }
};