class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            // Count odd-length palindromes (single character center)
            count += countPalindromesAroundCenter(s, i, i);
            // Count even-length palindromes (two character center)
            count += countPalindromesAroundCenter(s, i, i + 1);
        }
        return count;
    }
private:
    int countPalindromesAroundCenter(const string& s, int l, int r) {
        int current_count = 0;
        // Expand outwards while within bounds and characters match
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            current_count++;
            l--;
            r++;
        }
        return current_count;
    }
};
