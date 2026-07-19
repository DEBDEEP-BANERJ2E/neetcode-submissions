class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        // Pair up {position, time_to_target}
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
// Sort cars based on position in descending order (closest to target first)
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, 
        const pair<int, double>& b) {
            return a.first > b.first;
        });
        stack<double> st;
        for (int i = 0; i < n; i++) {
            double currentTime = cars[i].second;
    // If the stack is empty, or the current car takes strictly MORE time 
    // than the fleet ahead of it, it becomes a new fleet leader.
            if (st.empty() || currentTime > st.top())
                st.push(currentTime);
    // If currentTime <= st.top(), this car catches up to the fleet ahead 
            // and absorbs into it, so we do nothing.
        }
// The number of unique fleet leaders remaining in the stack is our answer
        return st.size();
    }
};
