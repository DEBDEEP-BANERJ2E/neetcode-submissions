class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize with n, since the loop indices will only go up to n - 1
        int result = n; 
        
        for (int i = 0; i < n; ++i) {
    // XOR the running result with both the index and the value at that index
            result ^= i ^ nums[i];
        }
        
        return result;
    }
};
