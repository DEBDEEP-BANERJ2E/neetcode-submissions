class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        
        // We only need to jump until our right pointer can reach the end
        while (r < nums.size() - 1) {
            int farthest = 0;
            
// Check all indices in the current jump window to find the farthest reach
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]);
            }
            
            // Move to the next jump window
            l = r + 1;
            r = farthest;
            
            // We successfully took one more jump
            jumps++;
        }
        
        return jumps;
    }
};
