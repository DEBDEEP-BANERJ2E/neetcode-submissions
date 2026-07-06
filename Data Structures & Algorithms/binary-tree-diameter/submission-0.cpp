class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;
    }

private:
    int dfs(TreeNode* node, int& max_diameter) {
        // Base case: null node has a height of 0
        if (!node)
            return 0;
        // Recursively find the height of left and right subtrees
        int left_height = dfs(node->left, max_diameter);
        int right_height = dfs(node->right, max_diameter);
        
        // The diameter passing through the current node is the sum of left and right heights
        max_diameter = max(max_diameter, left_height + right_height);
        
        // Return the height of the tree rooted at this node
        return 1 + max(left_height, right_height);
    }
};
