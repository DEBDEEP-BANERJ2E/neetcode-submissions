class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Nodes are labeled from 1 to n, so we allocate n + 1 space.
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 1);
        
        // Initialize DSU: each node is its own parent initially
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        
        // Process each edge
        for (const auto& edge : edges) {
            // If union fails, it means the edge creates a cycle
            if (!unionNodes(edge[0], edge[1], parent, rank))
                return edge;
        }
        return {};
    }

private:
    // Find the root of the node with Path Compression optimization
    int find(int node, vector<int>& parent) {
        if (parent[node] != node)
            parent[node] = find(parent[node], parent); 
        return parent[node];
    }
    
    // Union two nodes by rank. Returns false if they are already connected.
    bool unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        
        // Cycle detected: they are already in the same component
        if (rootU == rootV)
            return false;
        
        // Union by rank optimization to keep trees shallow
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
            rank[rootU] += rank[rootV];
        } else {
            parent[rootU] = rootV;
            rank[rootV] += rank[rootU];
        }
        return true;
    }
};
