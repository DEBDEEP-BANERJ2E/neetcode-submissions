class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int it : nums){
            if(s.count(it)==1) return true;
            else s.insert(it);
        }
        return false;
    }
};