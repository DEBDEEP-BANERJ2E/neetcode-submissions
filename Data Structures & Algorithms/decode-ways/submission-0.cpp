class Solution {
public:
    int numDecodings(string s) {
        // If the string starts with '0', it's entirely invalid
        if (s.empty() || s[0] == '0') return 0;
        // Base cases for our DP
        int twoBack = 1; // Represents the empty string before the first digit
        int oneBack = 1; // Represents the first valid digit
        for (int i = 1; i < s.length(); ++i) {
            int currentWays = 0;
            // 1. Check if the single current digit is valid (1-9)
            if (s[i] != '0') currentWays += oneBack;
            // 2. Check if the two-digit combination is valid (10-26)
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) currentWays += twoBack;
            // Shift our window forward for the next iteration
            twoBack = oneBack;
            oneBack = currentWays;
        }
        return oneBack;
    }
};
