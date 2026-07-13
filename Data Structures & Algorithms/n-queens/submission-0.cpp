class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; vector<bool> cols(n, false);
        vector<string> board(n, string(n, '.'));
        vector<bool> posDiag(2 * n - 1, false); //Tracks row + col
        vector<bool> negDiag(2 * n - 1, false); //Tracks row - col + (n - 1)
        backtrack(0, n, board, cols, posDiag, negDiag, result);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, 
    vector<bool>& posDiag, vector<bool>& negDiag, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board); return;
        }
        for (int col = 0; col < n; ++col) {
            int pos = row + col;
            int neg = row - col + (n - 1); // Offset to avoid negative indices
            if (cols[col] || posDiag[pos] || negDiag[neg]) continue;
            board[row][col] = 'Q';
            cols[col] = true;
            posDiag[pos] = true;
            negDiag[neg] = true;
            backtrack(row + 1, n, board, cols, posDiag, negDiag, result);
            board[row][col] = '.';
            cols[col] = false; posDiag[pos] = false; negDiag[neg] = false;
        }
    }
};
