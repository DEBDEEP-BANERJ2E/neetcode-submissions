class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        if(s.size() != t.size()) return false;

        vector<int> sCount(26,0);
        vector<int> tCount(26,0);

        for(int i=0; i<s.size(); i++){
            sCount[s[i]-'a']++;
            tCount[t[i]-'a']++;
        }

        for(int j=0; j<26; j++){
            if(sCount[j] != tCount[j]) return false;
        }
        return true;
    }
};
