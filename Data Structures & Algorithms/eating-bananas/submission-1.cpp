class Solution {
private:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;
            if (totalHours > h) return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(piles, h, mid)) {
                ans = mid;  
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};