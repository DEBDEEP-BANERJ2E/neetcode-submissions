class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> n;
        for(int i : nums){
            if(n.count(i)) return true;
            n.insert(i);
        }
        return false;
    }
};