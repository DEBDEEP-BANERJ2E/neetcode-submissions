class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 2) {
            return n;
        }
        
        // We only need to store the previous two steps to calculate 
        // the current one
        int stepOne = 2; // Ways to reach (n-1) initially step 2
        int stepTwo = 1; // Ways to reach (n-2) initially step 1
        int currentWays = 0;
        
        // Start calculating from step 3 up to n
        for (int i = 3; i <= n; ++i) {
            currentWays = stepOne + stepTwo;
            
            // Shift the window forward for the next iteration
            stepTwo = stepOne;
            stepOne = currentWays;
        }
        
        return currentWays;    
    }
};
