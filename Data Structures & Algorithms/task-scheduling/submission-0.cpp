class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char t : tasks)
            counts[t - 'A']++;
        priority_queue<int> maxHeap;
        for (int count : counts) {
            if (count > 0)
                maxHeap.push(count);
        }
        queue<pair<int, int>> q;
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0)
                    q.push({count, time + n});
            }
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
