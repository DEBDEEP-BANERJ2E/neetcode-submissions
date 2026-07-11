class MedianFinder {
private:
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;

public:
    MedianFinder() {
        // Initializes the MedianFinder object
    }
    void addNum(int num) {
        // Step 1: Add to max heap
        left_max_heap.push(num);
        // Step 2: Ensure max heap elements are <= min heap elements
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();
        // Step 3: Rebalance if right heap gets larger than left heap
        if (right_min_heap.size() > left_max_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    double findMedian() {
        // If odd number of elements, the extra one is in the max heap
        if (left_max_heap.size() > right_min_heap.size())
            return left_max_heap.top();
        // If even number of elements, take the average of the two middle elements
        return (left_max_heap.top() + right_min_heap.top()) / 2.0;
    }
};
