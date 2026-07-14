class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(); int n = p.length();
        // dp[i][j] represents if s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        // Base case: empty string matching patterns with '*' (like "a*b*")
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If characters match exactly or pattern has a '.'
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // If pattern has a '*'
                else if (p[j - 1] == '*') {
        // Option 1: Treat '*' as 0 occurrences of the previous character
                    dp[i][j] = dp[i][j - 2];
                    // Option 2: Treat '*' as 1 or more occurrences 
    // (only valid if the previous character matches the current s character)
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
