class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // Stores indices of elements
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window boundary
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove smaller elements from the back as they are useless
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index
            dq.push_back(i);
            
            // 4. Once the first window is fully formed, start adding to results
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
