class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the previous one
            if (intervals[i][0] < prevEnd) {
                removals++;
                // Greedily keep the interval that ends earlier
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                // No overlap, just update the boundary to the 
                // current interval's end
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};
