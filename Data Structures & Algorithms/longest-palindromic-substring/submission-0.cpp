class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0; int resStart = 0;
        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindromes (single character center)
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    resLen = r - l + 1;
                    resStart = l;
                }
                l--;
                r++;
            }
            // Check for even-length palindromes (two character center)
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    resLen = r - l + 1;
                    resStart = l;
                }
                l--;
                r++;
            }
        }
        // Extract and return the longest palindromic substring found
        return s.substr(resStart, resLen);
    }
};
