class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, 
    vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i)
            sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> result(queries.size(), -1); int i = 0;
        // Min-heap to store {interval_size, interval_end_time}
        // greater<> ensures the smallest interval size stays at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap;
        for (const auto& q : sortedQueries) {
            int queryVal = q.first; int originalIndex = q.second;
            // 1. Add all intervals that start before or at the current query
            while (i < intervals.size() && intervals[i][0] <= queryVal) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]}); i++;
            }
// 2. Remove all intervals from the heap that end before the current query
            // They are no longer valid for this query or any future queries
            while (!minHeap.empty() && minHeap.top().second < queryVal)
                minHeap.pop();
            // 3. The top element is the smallest valid interval for this query
            if (!minHeap.empty()) result[originalIndex] = minHeap.top().first;
        }
        return result;
    }
};
