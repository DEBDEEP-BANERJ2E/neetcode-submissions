class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Optimization: A valid tree MUST have exactly n - 1 edges.
        if (edges.size() != n - 1)
            return false;
        
        // Build the adjacency list for the undirected graph
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
// Run DFS starting from node 0. The parent of the root is arbitrarily -1.
        // If a cycle is detected, it's not a valid tree.
        if (hasCycle(0, -1, adj, visited))
            return false;
        
// After DFS, check if all nodes were reached (must be fully connected)
        for (bool v : visited)
            if (!v) return false;
        
        return true;
    }

private:
    bool hasCycle(int node, int parent, const vector<vector<int>>& adj, 
    vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            // If the neighbor hasn't been visited, recurse down that path
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, node, adj, visited))
                    return true;
            } 
// If the neighbor is already visited AND it is not the node we just came 
// from, it means we looped back around and found a cycle.
            else if (neighbor != parent)
                return true;
        }
        
        return false;
    }
};