class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, 
        greater<vector<int>>> minHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!minHeap.empty()) {
            vector<int> current = minHeap.top();
            minHeap.pop();
            int time = current[0];
            int r = current[1];
            int c = current[2];
            if (r == n - 1 && c == n - 1)
                return time;
            for (const auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    minHeap.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};
