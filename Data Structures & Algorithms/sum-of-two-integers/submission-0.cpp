class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // XOR gives us the sum without the carry
            int sum = a ^ b;
            
            // AND gives us the carry. We cast to unsigned int to 
            // prevent undefined behavior when shifting negative numbers left
            int carry = (unsigned int)(a & b) << 1;
            
            // Update a and b for the next iteration
            a = sum;
            b = carry;
        }
        
        return a;
    }
};
