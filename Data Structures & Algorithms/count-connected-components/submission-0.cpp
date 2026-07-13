class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 1);
        // Initially, each node is its own parent (n separate components)
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        // Iterate through all edges and try to union the nodes
        for (const auto& edge : edges) {
            if (unionNodes(edge[0], edge[1], parent, rank))
        // If a successful union happened, two components merged into one
                components--;
        }
        return components;
    }

private:
    // Find the root of the node with Path Compression optimization
    int find(int node, vector<int>& parent) {
        if (parent[node] != node)
            parent[node] = find(parent[node], parent); 
        return parent[node];
    }
    
    // Union two nodes by rank. Returns true if a merge happened.
    bool unionNodes(int n1, int n2, vector<int>& parent, vector<int>& rank) {
        int root1 = find(n1, parent);
        int root2 = find(n2, parent);
        
        // They are already in the same component
        if (root1 == root2) return false;
        
        // Union by rank optimization to keep trees shallow
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
            rank[root1] += rank[root2];
        } else {
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
        return true;
    }
};
