class Solution {
public:
    int change(int amount, vector<int>& coins) {
// Use unsigned int to prevent potential overflow during intermediate additions
        // dp[i] represents the number of combinations that make up amount i
        vector<unsigned int> dp(amount + 1, 0);
        
        // Base case: 1 way to make amount 0 (use no coins)
        dp[0] = 1;
        // Loop through coins first to ensure we are building combinations, 
        // not permutations
        for (int coin : coins) {
            // Update the dp array for all amounts that can include this coin
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};
