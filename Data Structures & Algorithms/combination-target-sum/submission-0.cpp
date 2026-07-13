class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        // Start backtracking from index 0 with an initial sum of 0
        backtrack(nums, target, 0, current, 0, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int target, int index, vector<int>& current, int currentSum, vector<vector<int>>& result) {
        // Base Case 1: We found a valid combination
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        // Base Case 2: We exceeded the target or ran out of elements
        if (currentSum > target || index >= nums.size())
            return;
        // Decision 1: Include the current element
        // Notice we pass 'index' instead of 'index + 1' to allow reusing the same element
        current.push_back(nums[index]);
        backtrack(nums, target, index, current, currentSum + nums[index], result);
        // Decision 2: Skip the current element (Backtrack)
        current.pop_back();
        backtrack(nums, target, index + 1, current, currentSum, result);
    }
};
