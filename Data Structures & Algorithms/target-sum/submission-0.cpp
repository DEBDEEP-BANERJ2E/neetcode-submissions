class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // It's impossible to reach the target if it's strictly greater than 
        // the sum of all elements, or if (totalSum + target) is an odd number.
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) return 0;
        // This is the new target sum we need to find subset combinations for
        int subsetSum = (totalSum + target) / 2;
        
        // dp[i] represents the number of ways to get the sum i
        vector<int> dp(subsetSum + 1, 0);
        
        // Base case: 1 way to get a sum of 0 (by choosing nothing)
        dp[0] = 1; 
        
        // Standard 0/1 Knapsack Bottom-Up DP
        for (int num : nums) {
    // Iterate backwards to ensure each number is only used once per subset
            for (int i = subsetSum; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        
        return dp[subsetSum];
    }
};
