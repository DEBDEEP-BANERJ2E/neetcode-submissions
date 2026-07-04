class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),left = 0;
        int cols = (rows > 0) ? matrix[0].size() : 0;
        int right = rows * cols - 1, val, mid;

        while (left <= right) {
            val = left + (right - left) / 2;
            mid = matrix[val / cols][val % cols];
            if (mid == target) return true;
            else if (mid < target) left = val + 1;
            else right = val - 1;
        }
        return false;
    }
};