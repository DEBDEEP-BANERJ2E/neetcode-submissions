class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<int> min_prefix(n);
        vector<int> max_suffix(n);

        for(int i=0; i<n; i++){
            if(i==0) min_prefix[i]=prices[i];
            else min_prefix[i]=min(min_prefix[i-1], prices[i]);
        }

        for(int j=n-1; j>=0; j--){
            if(j==(n-1)) max_suffix[j]=prices[j];
            else max_suffix[j]=max(max_suffix[j+1], prices[j]);
        }
        int net=0;
        for(int i=0; i<n; i++){
            net=max_suffix[i] - min_prefix[i];
            if(profit<net) profit=net;
        }
        return profit;
    }
};
