class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1;
        for(char c : s){
            s1[c]++;
        }
        for(char c : t){
            s1[c]--;
        }
        for(auto pair : s1){
            if(pair.second!=0) return false;
        }
        return true;
    }
};
