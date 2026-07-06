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
    int maxDepth(TreeNode* root) {
        // Base case: if the tree is empty, its depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Return 1 (for the current node) plus the max of the two depths
        return 1 + std::max(leftDepth, rightDepth);
        
        // Note: This can also be written in a single line:
        // return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
