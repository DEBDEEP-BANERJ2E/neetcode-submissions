class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundFirst = false;
        bool foundSecond = false;
        bool foundThird = false;
        
        for (const auto& t : triplets) {
    // 1. Skip any triplet that contains a value greater than the target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }
            
    // 2. Check if this valid triplet contains any of our needed target values
            if (t[0] == target[0]) foundFirst = true;
            if (t[1] == target[1]) foundSecond = true;
            if (t[2] == target[2]) foundThird = true;
            
    // Optimization: If we've found all three parts, we can stop early
            if (foundFirst && foundSecond && foundThird) {
                return true;
            }
        }
        
        // Return true only if we successfully found all target components
        return foundFirst && foundSecond && foundThird;
    }
};
