class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(); int n = word2.length();
// dp[i][j] stores the min operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // Base case: word1 is empty, must insert all characters of word2
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;
        // Base case: word2 is empty, must delete all characters of word1
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        // Fill the DP table bottom-up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
            // If characters match, no operation is needed for this step
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
            // Mismatch: take the minimum of Insert, Delete, or Replace
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j],    // Delete
                        dp[i - 1][j - 1] // Replace
                    });
                }
            }
        }
        return dp[m][n];
    }
};
