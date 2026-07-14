class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        // If total lengths don't match, it can't be an interleaved string
        if (m + n != s3.length()) return false;
        // We only need a 1D DP array of size n + 1 to track the current row
        vector<bool> dp(n + 1, false);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                // Base case: empty strings
                if (i == 0 && j == 0) dp[j] = true;
                // First row: can we form s3 using only characters from s2?
                else if (i == 0)
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                // First column: can we form s3 using only characters from s1?
                else if (j == 0)
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
// Standard case: check if we can extend the interleave from either s1 or s2
                else {
                    dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) || 
                            (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
        }
        return dp[n];
    }
};
