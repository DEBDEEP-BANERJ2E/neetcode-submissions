class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        
        for (int i = 0; i < 32; ++i) {
            // Extract the rightmost bit from n
            uint32_t bit = n & 1;
            
            // Shift res to the left to make room, then insert the bit
            res = (res << 1) | bit;
            
            // Shift n to the right to process the next bit on the next loop
            n >>= 1;
        }
        
        return res;
    }
};
