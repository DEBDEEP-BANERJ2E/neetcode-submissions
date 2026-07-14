class Solution {
private:
    // Helper function to calculate the sum of the squares of the digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            totalSum += (digit * digit);
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // Fast pointer moves twice as fast as the slow pointer
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        // If the fast pointer reached 1, it's a non-cyclical number
        return fast == 1;
    }
};
