/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxGain = INT_MIN;
        dfs(root, maxGain);
        return maxGain;
    }

private:
    int dfs(TreeNode* node, int& maxGain) {
        if (!node) return 0;
        int leftGain = max(dfs(node->left, maxGain), 0);
        int rightGain = max(dfs(node->right, maxGain), 0);
        int currentPathSum = node->val + leftGain + rightGain;
        maxGain = max(maxGain, currentPathSum);
        return node->val + max(leftGain, rightGain);
    }
};
