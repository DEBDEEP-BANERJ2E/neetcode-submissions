class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Create a padded array with 1s on the boundaries
        vector<int> A(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            A[i + 1] = nums[i];
        }
// dp[i][j] stores the max coins for bursting balloons in the range [i, j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // Iterate over the length of the ranges (from 1 to n)
        for (int len = 1; len <= n; ++len) {
            // Iterate over the starting index of the range
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1; 
        // Try making every balloon 'i' in the range the LAST one to burst
                for (int i = left; i <= right; ++i) {
                    int coins = dp[left][i - 1] + 
                                (A[left - 1] * A[i] * A[right + 1]) + 
                                dp[i + 1][right];
                                
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
// The result for bursting balloons from index 1 to n in the padded array
        return dp[1][n];
    }
};
