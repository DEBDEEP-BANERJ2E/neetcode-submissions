class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // This array will store the smallest tail of all increasing 
        // subsequences of length i+1 in sub[i].
        vector<int> sub;
        
        for (int x : nums) {
// If x is larger than all elements in sub, it extends the longest subsequence
            if (sub.empty() || sub.back() < x) {
                sub.push_back(x);
            } else {
                // Find the first element in sub that is >= x
                auto it = lower_bound(sub.begin(), sub.end(), x);
// Replace that element with x to maintain the smallest possible tails
                *it = x;
            }
        }
        
        // The length of the sub array represents the length of the LIS
        return sub.size();
    }
};
