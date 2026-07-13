class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int num_islands = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(grid, r, c, ROWS, COLS);
                }
            }
        }
        return num_islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c, int ROWS, int COLS) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        // Recursively visit all 4 adjacent directions
        dfs(grid, r + 1, c, ROWS, COLS); // Down
        dfs(grid, r - 1, c, ROWS, COLS); // Up
        dfs(grid, r, c + 1, ROWS, COLS); // Right
        dfs(grid, r, c - 1, ROWS, COLS); // Left
    }
};
