class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            // If the heap size exceeds k, pop the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};
