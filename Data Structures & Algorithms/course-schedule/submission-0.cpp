class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list graph
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            // To take pre[0], you must take pre[1] first.
            // Edge direction: pre[0] -> pre[1] 
            // (meaning we check prerequisites starting from the target course)
            adj[pre[0]].push_back(pre[1]);
        }
        // State tracking: 0 = unvisited, 1 = visiting, 2 = fully visited/safe
        vector<int> state(numCourses, 0);

        // Run DFS from every course in case the graph is disconnected
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state))
                    return false; // Cycle detected, impossible to finish
            }
        }
        
        return true; // No cycles found
    }

private:
    bool hasCycle(int node, const vector<vector<int>>& adj, 
    vector<int>& state) {
        // If we hit a node currently in our active path, it's a cycle
        if (state[node] == 1) return true; 
        
        // If we hit a node we've already cleared, it's safe
        if (state[node] == 2) return false;

        // Mark current node as 'visiting'
        state[node] = 1;

        // Recursively check all prerequisites for this course
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, state)) {
                return true;
            }
        }

        // Once all paths from this node are clear, mark it as 'safe'
        state[node] = 2;
        return false;
    }
};
