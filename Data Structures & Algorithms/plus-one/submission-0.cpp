class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // If the digit is less than 9, increment and we are done
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // Otherwise, it was a 9, so it becomes 0 and 
            // we carry over to the next
            digits[i] = 0;
        }
        
        // If we exit the loop, it means the number was something like 999
        // The array is now 000, so we insert a 1 at the beginning
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
