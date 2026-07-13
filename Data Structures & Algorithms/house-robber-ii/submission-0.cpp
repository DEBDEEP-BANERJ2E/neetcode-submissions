class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Return the maximum of the two possible non-overlapping ranges
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
// Helper function that runs standard House Robber logic on a specific range
    int robRange(const vector<int>& nums, int start, int end) {
        int rob1 = 0;
        int rob2 = 0;
        
        for (int i = start; i <= end; ++i) {
            int current_max = max(nums[i] + rob1, rob2);
            // Shift the window forward
            rob1 = rob2;
            rob2 = current_max;
        }
        return rob2;
    }
};
