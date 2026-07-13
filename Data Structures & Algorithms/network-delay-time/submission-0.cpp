class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build the adjacency list: adj[u] = {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times)
            adj[time[0]].push_back({time[1], time[2]});

        // 2. Min-heap to store {current_time, node}
// priority_queue in C++ acts as a max-heap by default, 
// so we use greater<> to make it a min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        
// 3. Distance array to track the minimum time to reach each node (1-indexed)
// Using 1e9 as a safe proxy for infinity to avoid integer overflow 
// during addition
        vector<int> dist(n + 1, 1e9);
        
        // Start from the source node k
        pq.push({0, k});
        dist[k] = 0;

        // 4. Dijkstra's Algorithm
        while (!pq.empty()) {
            auto [curr_time, u] = pq.top();
            pq.pop();

// Optimization: if we already found a shorter path to u, 
// skip stale queue entries
            if (curr_time > dist[u])
                continue;

            // Explore neighbors
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
            // Relaxation step: if we found a strictly shorter path to v
                if (curr_time + weight < dist[v]) {
                    dist[v] = curr_time + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // 5. Find the maximum time it takes to reach any node
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9)
                return -1; // If any node remains unreachable
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};