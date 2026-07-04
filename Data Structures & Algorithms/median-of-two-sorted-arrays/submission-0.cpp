class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int m = A.size();
        int n = B.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int total = m + n, half = (total + 1) / 2, low = 0, high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = half - i;

            int A_left = (i > 0) ? A[i - 1] : INT_MIN;
            int A_right = (i < m) ? A[i] : INT_MAX;
            int B_left = (j > 0) ? B[j - 1] : INT_MIN;
            int B_right = (j < n) ? B[j] : INT_MAX;

            if (A_left <= B_right && B_left <= A_right) {
                if (total % 2 != 0)
                    return max(A_left, B_left);
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
            } 
            else if (A_left > B_right)
                high = i - 1;
            else
                low = i + 1;
        }
        return 0.0;
    }
};
