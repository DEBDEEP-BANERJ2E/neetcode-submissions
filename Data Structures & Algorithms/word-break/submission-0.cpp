class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
// dp[i] represents whether the substring s[i...n-1] can be segmented
        vector<bool> dp(n + 1, false);
// Base case: an empty string (reaching the end) is technically a valid break
        dp[n] = true;
        // Work backwards from the end of the string to the beginning
        for (int i = n - 1; i >= 0; --i) {
            for (const string& w : wordDict) {
            // 1. Check if the word fits within the remaining string bounds
            // 2. Check if the substring matches the dictionary word
                if (i + w.length() <= n && s.substr(i, w.length()) == w) {
                // If it matches, the current index's success depends on 
                // the success of the index immediately following this word
                    dp[i] = dp[i + w.length()];
                }
                // If we found a valid combination from this index, 
                // stop checking other words
                if (dp[i]) {
                    break;
                }
            }
        }
        // dp[0] holds the result for the entire string
        return dp[0];
    }
};
