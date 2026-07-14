/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        // Sort the intervals based on their start times 
        // using a lambda function
        sort(intervals.begin(), intervals.end(), 
        [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // Iterate through the sorted intervals to check for overlaps
        for (int i = 1; i < intervals.size(); ++i) {
            // If the current meeting starts before the previous one ends, 
            // there's a conflict
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        // No conflicts found
        return true;
    }
};
