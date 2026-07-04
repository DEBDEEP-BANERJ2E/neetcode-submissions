class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, left=0, n=prices.size(), net=0;
        for(int right=1; right<n; right++){
            net=prices[right] - prices[left];
            if(prices[left] < prices[right]){
                if(profit<net)
                    profit=net;
            }
            else 
                left=right;
        }
        return profit;
    }
};
