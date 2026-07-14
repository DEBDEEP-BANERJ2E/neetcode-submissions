class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        int top = 0; int bottom = matrix.size() - 1;
        int left = 0; int right = matrix[0].size() - 1;
        while (left <= right && top <= bottom) {
            // Traverse from left to right across the top boundary
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            top++; // Shrink top boundary
            // Traverse from top to bottom down the right boundary
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            right--; // Shrink right boundary
            // Crucial check: if our boundaries crossed, we are done.
            // This prevents double-counting in non-square matrices.
            if (top > bottom || left > right) break;
            // Traverse from right to left across the bottom boundary
            for (int i = right; i >= left; --i)
                result.push_back(matrix[bottom][i]);
            bottom--; // Shrink bottom boundary
            // Traverse from bottom to top up the left boundary
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            left++; // Shrink left boundary
        }
        return result;
    }
};
