class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(); int n = matrix[0].size(); int longestPath = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                longestPath = max(longestPath, dfs(matrix, i, j, memo));
        }
        return longestPath;
    }
private:
    int dfs(const vector<vector<int>>& matrix, int r, int c, 
    vector<vector<int>>& memo) {
        if (memo[r][c] != 0) return memo[r][c];
        int maxPath = 1; int m = matrix.size(); int n = matrix[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : dirs) {
            int nr = r + dir.first; int nc = c + dir.second;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
            matrix[nr][nc] > matrix[r][c])
                maxPath = max(maxPath, 1 + dfs(matrix, nr, nc, memo));
        }
        // Save the result to our memoization table before returning
        memo[r][c] = maxPath;
        return maxPath;
    }
};