class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, 
    int dst, int k) {
// Initialize prices array with a large proxy for infinity to avoid overflow
        vector<int> prices(n, 1e9);
        prices[src] = 0;
        // Loop k + 1 times since k stops means k + 1 edges
        for (int i = 0; i < k + 1; ++i) {
// Temporary array to store updates for this specific iteration (stop level)
            vector<int> tmpPrices = prices;
            // Go through all available flights
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];
                // If the departure city is reachable, 
                // try to find a cheaper path to the destination
                if (prices[u] != 1e9) {
                    tmpPrices[v] = min(tmpPrices[v], prices[u] + price);
                }
            }
            // Commit the updates for the next iteration
            prices = tmpPrices;
        }
// If the destination price is still infinity, it's unreachable within k stops
        return prices[dst] == 1e9 ? -1 : prices[dst];
    }
};
