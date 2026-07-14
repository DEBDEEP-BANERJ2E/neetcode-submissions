class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            // Pop the last digit off x
            int digit = x % 10;
            x /= 10;
            
            // Check for positive integer overflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            // Check for negative integer overflow
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            // Push the digit onto the back of res
            res = res * 10 + digit;
        }
        
        return res;
    }
};
