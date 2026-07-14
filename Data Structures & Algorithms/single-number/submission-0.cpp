class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // XOR all numbers together
        for (int num : nums) {
            result ^= num;
        }
        
        // The duplicates cancel out to 0, leaving only the single number
        return result;
    }
};
