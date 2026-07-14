class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // Initialize states
        int hold = INT_MIN; // Max profit if we currently hold a stock
        int sold = 0;       // Max profit if we just sold a stock today
        int rest = 0;       // Max profit if we are resting/cooldown today
        for (int price : prices) {
            // Store the previous 'sold' state because we need it to 
            // calculate the new 'rest'
            int prev_sold = sold;
            
            // If we sell today, we must have been holding yesterday
            sold = hold + price;
            
            // If we hold today, we either kept holding from yesterday, 
            // or we bought today after resting yesterday
            hold = max(hold, rest - price);
            
            // If we rest today, we either kept resting from yesterday, 
            // or we were forced into cooldown because we sold yesterday
            rest = max(rest, prev_sold);
        }
        // The maximum profit will always end in either
        // the 'sold' or 'rest' state.
        // It makes no sense to end the timeline holding a stock.
        return max(sold, rest);
    }
};
