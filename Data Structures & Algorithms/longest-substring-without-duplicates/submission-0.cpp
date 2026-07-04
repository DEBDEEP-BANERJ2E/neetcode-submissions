class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> s1;
        int l = 0;
        int length = 0;

        for (int r = 0; r < s.size(); r++) {
            while (s1.find(s[r]) != s1.end()) {
                s1.erase(s[l]);
                l++;
            }
            s1.insert(s[r]);
            length = max(length, r - l + 1);
        }

        return length;
    }
};