class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_fruits = 0;
        // Step 1: Scan grid to populate the queue with initially rotten fruits
        // and count the fresh fruits.
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    fresh_fruits++;
            }
        }
        // If there are no fresh fruits to begin with, 0 minutes are needed
        if (fresh_fruits == 0) return 0;
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // Step 2: Multi-source BFS
        // Only run while there are items in the queue AND fresh fruits remain
        while (!q.empty() && fresh_fruits > 0) {
            int level_size = q.size();
            
            // Process the current level (current minute)
            for (int i = 0; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                // Explore all 4 adjacent directions
                for (auto dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    // If out of bounds or not a fresh fruit, skip
                    if (nr < 0 || nr >= ROWS || nc < 0 || 
                    nc >= COLS || grid[nr][nc] != 1)
                        continue;
                    // Rot the fresh fruit
                    grid[nr][nc] = 2; fresh_fruits--;
                    // Push to queue to process in the next minute
                    q.push({nr, nc});
                }
            }
            minutes++;
        }
        // Step 3: Check if all fresh fruits were successfully rotted
        return fresh_fruits == 0 ? minutes : -1;
    }
};
