class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0; int ROWS = grid.size(); int COLS = grid[0].size();
        // Iterate over every cell in the grid
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                // If we find land, calculate its full area using DFS
                if (grid[r][c] == 1) {
                    int current_area = dfs(grid, r, c, ROWS, COLS);
                    max_area = max(max_area, current_area);
                }
            }
        }
        return max_area;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int ROWS, int COLS) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0)
            return 0; // Base case: out of bounds or we hit water (0)
        grid[r][c] = 0; // Mark the current cell as visited by sinking it
        return 1 + dfs(grid, r + 1, c, ROWS, COLS) 
                 + dfs(grid, r - 1, c, ROWS, COLS) 
                 + dfs(grid, r, c + 1, ROWS, COLS) 
                 + dfs(grid, r, c - 1, ROWS, COLS);
    }
};
