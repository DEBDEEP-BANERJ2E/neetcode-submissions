class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets)
            adj[ticket[0]].push_back(ticket[1]);
        for (auto& pair : adj)
            sort(pair.second.rbegin(), pair.second.rend());
        vector<string> itinerary;
        // Start Hierholzer's Algorithm
        dfs("JFK", adj, itinerary);
    // Reverse the post-order path to get the correct chronological path
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
private:
    void dfs(const string& airport, unordered_map<string, 
    vector<string>>& adj, vector<string>& itinerary) {
        // While there are still outgoing flights from this airport
        while (!adj[airport].empty()) {
// Get the lexicographically smallest destination and remove the ticket
            string next_airport = adj[airport].back();
            adj[airport].pop_back();
            // Traverse further down the path
            dfs(next_airport, adj, itinerary);
        }
        // No more outgoing flights; we've hit the end of a path
        itinerary.push_back(airport);
    }
};
