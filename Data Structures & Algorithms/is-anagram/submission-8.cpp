class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26,0);
        vector<int> tCount(26,0);
        if(s.size() != t.size()) return false;

        for(int c=0; c <s.size(); c++){
            sCount[s[c]-'a']++;
            tCount[t[c]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(sCount[i] != tCount[i]) return false;
        }
        return true;
    }
};
