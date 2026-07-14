class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        // Start iterating from the second element
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            
            // We need to store currMax * n in a temporary variable 
            // because we will overwrite currMax before calculating currMin
            int tmpMax = currMax * n;
            int tmpMin = currMin * n;

            // Calculate the new max and min ending at the current element
            currMax = max(n, max(tmpMax, tmpMin));
            currMin = min(n, min(tmpMax, tmpMin));

            // Update the global maximum result
            res = max(res, currMax);
        }

        return res;
    }
};
