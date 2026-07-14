class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(int i : nums){
            if(n.find(i)!=n.end()) return true;
            n.insert(i);
        }
        return false;
    }
};