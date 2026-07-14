class Solution {
public:
    int maxSubArray(vector<int>& nums) {
// Initialize both the running sum and the global max with the first element
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        // Start iterating from the second element
        for (int i = 1; i < nums.size(); ++i) {
        // Decide whether to add the current number to the existing subarray 
            // or start a new subarray from the current number
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update the global maximum if the current running sum is larger
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
