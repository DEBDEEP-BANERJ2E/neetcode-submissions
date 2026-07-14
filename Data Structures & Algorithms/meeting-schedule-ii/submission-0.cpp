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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        int n = intervals.size();
        vector<int> starts(n); vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int count = 0; int maxRooms = 0;
        int s = 0; int e = 0;
        // We only need to iterate until all meetings have started
        while (s < n) {
// If the next meeting starts before the earliest ending meeting finishes
            if (starts[s] < ends[e]) {
                count++; s++;
            } 
            // If a meeting has ended, a room frees up
            else {
                count--; e++;
            }
            // Track the peak number of simultaneous meetings
            maxRooms = max(maxRooms, count);
        }
        return maxRooms;
    }
};
