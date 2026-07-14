class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // dp[i][j] will store the LCS of text1[0..i-1] and text2[0..j-1]
        // Initialized with 0s to automatically handle our base cases
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Build the DP table bottom-up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
// Characters match: extend the subsequence from the previous characters
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
// Mismatch: take the max of excluding the current char of text1 or text2
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
