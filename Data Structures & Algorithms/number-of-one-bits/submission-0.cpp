class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // Loop until all 1 bits have been erased
        while (n > 0) {
            // This operation zeroes out the least significant '1' bit
            n &= (n - 1);
            count++;
        }
        
        return count;
    }
};
