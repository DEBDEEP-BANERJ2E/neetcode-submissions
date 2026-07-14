class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array with 'amount + 1' acting as our infinity
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins needed for amount 0
        dp[0] = 0;
        
        // Calculate the minimum coins needed for each amount up to the target
        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                // If the coin value is less than or equal to the current amount
                if (a - c >= 0) {
                    // Update the dp value with the minimum coins required
                    dp[a] = min(dp[a], 1 + dp[a - c]);
                }
            }
        }
        
        // If the target amount's value hasn't changed from infinity, 
        // it's unreachable
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
