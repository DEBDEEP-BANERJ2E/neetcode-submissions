class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        // Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Start by adding the first interval
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // merged.back() gives us a reference to the last interval 
            // we processed
            vector<int>& lastMerged = merged.back();
            
            // If the current interval overlaps with the last merged one
            if (intervals[i][0] <= lastMerged[1]) {
                // Update the end value to encompass both intervals
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                // No overlap, so we can safely add it as a new distinct 
                // interval
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
