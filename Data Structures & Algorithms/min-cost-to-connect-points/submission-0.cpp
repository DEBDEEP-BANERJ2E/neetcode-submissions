class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Min-heap stores pairs of {cost, node_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

        vector<bool> visited(n, false);
        // Start from node 0 with 0 cost
        pq.push({0, 0});
        int total_cost = 0;
        int connected = 0;
        
        // Loop until all n points are connected
        while (connected < n) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            // If the node is already part of the MST, skip it
            if (visited[u]) {
                continue;
            }
            
            // Include this node in the MST
            visited[u] = true;
            total_cost += cost;
            connected++;
            
            // Calculate distances to all other unvisited nodes and 
            // add to heap
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + 
                               abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }
        return total_cost;
    }
};
