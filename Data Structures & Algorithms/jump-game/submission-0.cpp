class Solution {
public:
    bool canJump(vector<int>& nums) {
        // The initial target is the last index
        int goal = nums.size() - 1;
        
        // Iterate backwards starting from the second to last index
        for (int i = nums.size() - 2; i >= 0; --i) {
            // If we can reach the current goal from index i,
            // update the goal to index i
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        
        // If the goal reaches the starting index, it's possible
        return goal == 0;
    }
};
