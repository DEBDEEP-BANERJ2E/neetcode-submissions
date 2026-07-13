class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If we've made a decision for every element
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Decision 1: Include the current element
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);

        // Decision 2: Exclude the current element (Backtrack)
        current.pop_back();
        backtrack(nums, index + 1, current, result);
    }
};
