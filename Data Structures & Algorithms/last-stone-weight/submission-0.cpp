class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Initialize a max-heap with the stones array
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // Simulating the process until 0 or 1 stone remains
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); // Heaviest stone
            maxHeap.pop();
            
            int x = maxHeap.top(); // Second heaviest stone
            maxHeap.pop();
            
            // If they are not equal, the remaining piece goes back into the heap
            if (x != y) {
                maxHeap.push(y - x);
            }
        }
        
        // If the heap is empty, return 0; otherwise return the last remaining stone
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
