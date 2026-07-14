class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        bool firstCol = false;
        for (int r = 0; r < ROWS; ++r) {
            if (matrix[r][0] == 0) firstCol = true;
            for (int c = 1; c < COLS; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0; 
                    matrix[r][0] = 0;
                }
            }
        }
        for (int r = 1; r < ROWS; ++r) {
            for (int c = 1; c < COLS; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int c = 0; c < COLS; ++c)
                matrix[0][c] = 0;
        }
        if (firstCol) {
            for (int r = 0; r < ROWS; ++r)
                matrix[r][0] = 0;
        }
    }
};
