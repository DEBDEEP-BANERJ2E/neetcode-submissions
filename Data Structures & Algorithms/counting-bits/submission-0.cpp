class Solution {
public:
    vector<int> countBits(int n) {
        // Create an array of size n + 1, initialized to 0
        // (This automatically handles our base case: dp[0] = 0)
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // The number of 1s in 'i' is the number of 1s in 'i / 2' 
            // plus 1 if 'i' is an odd number (checked via i & 1)
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};
