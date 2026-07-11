class KthLargest {
private:
    int minHeapSize;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        minHeapSize = k;
        for (int num : nums) {
            minHeap.push(num);
            // If size exceeds k, remove the smallest element
            if (minHeap.size() > minHeapSize)
                minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > minHeapSize)
            minHeap.pop();
        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};
