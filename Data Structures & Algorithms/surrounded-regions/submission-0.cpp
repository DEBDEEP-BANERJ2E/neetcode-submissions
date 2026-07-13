class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int ROWS = board.size();
        int COLS = board[0].size();
        
        // 1. Run DFS on the left and right borders
        for (int r = 0; r < ROWS; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0, ROWS, COLS);
            if (board[r][COLS - 1] == 'O') dfs(board, r, COLS - 1, ROWS, COLS);
        }
        
        // 2. Run DFS on the top and bottom borders
        for (int c = 0; c < COLS; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c, ROWS, COLS);
            if (board[ROWS - 1][c] == 'O') dfs(board, ROWS - 1, c, ROWS, COLS);
        }
        
        // 3. Capture surrounded regions ('O' -> 'X') and 
        // restore safe ones ('T' -> 'O')
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Captured
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // Restored
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, int ROWS, int COLS) {
        // Base case: Out of bounds or not an 'O'
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
            return;
        }
        
        // Mark the current 'O' as temporarily safe
        board[r][c] = 'T';
        
        // Explore all 4 adjacent directions
        dfs(board, r + 1, c, ROWS, COLS); // Down
        dfs(board, r - 1, c, ROWS, COLS); // Up
        dfs(board, r, c + 1, ROWS, COLS); // Right
        dfs(board, r, c - 1, ROWS, COLS); // Left
    }
};
