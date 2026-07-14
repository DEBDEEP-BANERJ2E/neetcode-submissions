class Solution {
public:
    int uniquePaths(int m, int n) {
        // We only need a 1D array to store the current row's path counts.
        // Initialize with 1s because there is only 1 way to reach any cell 
        // in the very first row (by strictly moving right).
        vector<int> row(n, 1);
        
        // Iterate through the remaining m - 1 rows
        for (int i = 1; i < m; ++i) {
        // For each cell in the row, starting from the second column (index 1)
            for (int j = 1; j < n; ++j) {
                // The new ways to reach this cell = 
                // ways to reach cell above it (current row[j]) + 
                // ways to reach cell to the left (new row[j - 1])
                row[j] += row[j - 1];
            }
        }
        // The last element in our array will hold the result 
        // for the bottom-right corner
        return row[n - 1];
    }
};
