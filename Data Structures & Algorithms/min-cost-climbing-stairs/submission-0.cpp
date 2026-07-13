class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // The cost to reach the 0th or 1st step is 0, since we can start there.
        int two_steps_before = 0;
        int one_step_before = 0;
        
        // Calculate the minimum cost to reach each step from 2 up to the top (n)
        for (int i = 2; i <= n; ++i) {
            int current_cost = min(one_step_before + cost[i - 1], 
                                   two_steps_before + cost[i - 2]);
            
            // Shift our window forward for the next iteration
            two_steps_before = one_step_before;
            one_step_before = current_cost;
        }
        
        // The cost to reach the very top
        return one_step_before;
    }
};
