class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(); int n = t.length();
        // We use unsigned int to prevent potential integer overflow during 
// additions, which is a common edge case in C++ for this specific problem.
        vector<unsigned int> dp(n + 1, 0);
        // Base case: an empty string 't' can be formed exactly 1 way
        dp[0] = 1;
        // Iterate through each character in s
        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through t
            for (int j = n; j >= 1; --j) {
                // If characters match, we can either use s[i-1] or ignore it
                if (s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
                // If they don't match, dp[j] implicitly remains the same
            }
        }
        return dp[n];
    }
};
