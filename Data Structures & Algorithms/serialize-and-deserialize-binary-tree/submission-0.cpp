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

class Codec {
public:
    string serialize(TreeNode* root) {
        string result = ""; serializeDFS(root, result);
        return result;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data); return deserializeDFS(ss);
    }
private:
    void serializeDFS(TreeNode* node, string& result) {
        if (!node) {
            result += "N,"; return;
        }
        result += to_string(node->val) + ",";
        serializeDFS(node->left, result);
        serializeDFS(node->right, result);
    }
    TreeNode* deserializeDFS(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',')) return nullptr;
        if (token == "N") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);
        return node;
    }
};
