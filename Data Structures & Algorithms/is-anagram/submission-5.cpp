class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1;
        if(s.size()!=t.size()) return false;
        for(int i=0; i<s.size(); i++){
            s1[s[i]]++;
            s1[t[i]]--;
        }
        for(auto pair : s1){
            if(pair.second!=0) return false;
        }
        return true;
    }
};
