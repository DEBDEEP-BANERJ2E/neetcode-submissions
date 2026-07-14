class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0; // Minimum possible open left parentheses
        int leftMax = 0; // Maximum possible open left parentheses
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { // c == '*'
                leftMin--; // Try treating '*' as ')'
                leftMax++; // Try treating '*' as '('
            }
            // If the maximum possible open parentheses drops below 0, 
            // there are unconditionally too many ')' to salvage the string.
            if (leftMax < 0) return false;
            // We cannot have a negative number of required open parentheses.
            // If leftMin < 0, it means we should treat a previous '*' as an 
        // empty string instead of a ')' to keep our minimum requirement at 0.
            if (leftMin < 0) leftMin = 0;
        }
        // If the minimum required open parentheses is 0, the string is 
        // perfectly balanced
        return leftMin == 0;
    }
};
