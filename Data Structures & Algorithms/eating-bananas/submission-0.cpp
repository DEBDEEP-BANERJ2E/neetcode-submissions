class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, k;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;
        long long total_time;

        while (low <= high) {
            k = low + (high - low) / 2;
            total_time = 0;

            for (int pile : piles)
                total_time += (pile + k - 1) / k;

            if (total_time <= h) {
                result = k;
                high = k - 1;
            } 
            else
                low = k + 1;
        }
        return result;
    }
};
