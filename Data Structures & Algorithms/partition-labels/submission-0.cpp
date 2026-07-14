class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Array to store the last index of each of the 26 lowercase letters
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> result;
        int size = 0;
        int end = 0;

        for (int i = 0; i < s.length(); ++i) {
            size++;
            // Greedily extend the boundary to the furthest last occurrence
            end = max(end, lastIndex[s[i] - 'a']);

            // When we reach the boundary, we've formed a valid partition
            if (i == end) {
                result.push_back(size);
                size = 0; // Reset size for the next partition
            }
        }

        return result;
    }
};
