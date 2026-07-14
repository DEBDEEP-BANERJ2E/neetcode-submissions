class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        // If the total sum is odd, we can't divide it into two equal integers
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        // dp[i] will be true if we can make a subset sum exactly equal to i
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum of 0 is always possible
        // Iterate through each number in the array
        for (int num : nums) {
            // Iterate backwards from target down to num
            for (int i = target; i >= num; --i) {
                // We can achieve sum 'i' if we could already achieve it, 
                // OR if we could achieve the sum (i - num) before adding 'num'
                dp[i] = dp[i] || dp[i - num];
            }
            // Optimization: If we've already found a way to make the target, 
            // we can stop early
            if (dp[target]) return true;
        }
        return dp[target];
    }
};
