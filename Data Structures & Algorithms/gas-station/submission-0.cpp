class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0; int total_cost = 0;
        int current_gas = 0; int start_index = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            // Add the net gas gain/loss for the current station
            current_gas += gas[i] - cost[i];
            // If we run out of gas, this station and all previous ones 
            // in the current sequence cannot be the start.
            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0; // Reset tank for the new potential start
            }
        }
// If we don't have enough gas overall to cover the total cost, it's impossible
        if (total_gas < total_cost)
            return -1;
        
        // Because a solution is guaranteed if total_gas >= total_cost, 
        // the last start_index we set must be the correct one.
        return start_index;
    }
};
