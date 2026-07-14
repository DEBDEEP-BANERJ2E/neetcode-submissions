class Solution {
public:
    double myPow(double x, int n) {
        // Cast n to a 64-bit integer to prevent overflow when negating INT_MIN
        long long N = n;
        // Handle negative powers by inverting the base and 
        // making the exponent positive
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    
private:
    double fastPow(double x, long long n) {
        // Base case: Any number to the power of 0 is 1
        if (n == 0) return 1.0;
        // Recursively calculate the power of half of n
        double half = fastPow(x, n / 2);
        // If n is even, square the half result
        if (n % 2 == 0) return half * half;
        // If n is odd, square the half result and multiply by one extra x
        else return half * half * x;
    }
};
