class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(char it : s) mp[it]+=1;
        for(char it : t) mp[it]-=1;
        for(auto it : mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
