class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        for (int c = 0; c < COLS; ++c) {
            dfs(heights, pac, 0, c, heights[0][c], ROWS, COLS);
            dfs(heights, atl, ROWS - 1, c, heights[ROWS - 1][c], ROWS, COLS);
        }
        for (int r = 0; r < ROWS; ++r) {
            dfs(heights, pac, r, 0, heights[r][0], ROWS, COLS);
            dfs(heights, atl, r, COLS - 1, heights[r][COLS - 1], ROWS, COLS);
        }
        vector<vector<int>> result;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
    
private:
    void dfs(const vector<vector<int>>& heights, 
    vector<vector<bool>>& visited, int r, int c, int prevHeight, 
    int ROWS, int COLS) {
        
        // Base case: Out of bounds, already visited, 
        // or water cannot flow "up"
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || 
            visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        // Mark the current cell as reachable
        visited[r][c] = true;
        
        // Explore all 4 adjacent directions
        dfs(heights, visited, r + 1, c, heights[r][c], ROWS, COLS);
        dfs(heights, visited, r - 1, c, heights[r][c], ROWS, COLS);
        dfs(heights, visited, r, c + 1, heights[r][c], ROWS, COLS);
        dfs(heights, visited, r, c - 1, heights[r][c], ROWS, COLS);
    }
};
