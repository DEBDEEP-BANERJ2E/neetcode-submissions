class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0; // Represents the max loot up to house i-2
        int rob2 = 0; // Represents the max loot up to house i-1
        
        // Iterate through each house's money
        for (int n : nums) {
            // Calculate the max we can rob if we are at the current house 'n'
            int current_max = max(n + rob1, rob2);
            
            // Shift our window forward for the next iteration
            rob1 = rob2;
            rob2 = current_max;
        }
        
        // rob2 will hold the maximum possible loot by the end of the array
        return rob2;
    }
};
