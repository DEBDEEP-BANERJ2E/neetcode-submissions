class TrieNode {
public:
    TrieNode* children[26];
    int wordIndex;
    TrieNode() {
        wordIndex = -1;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};
class Solution {
private:
    TrieNode* root;
    vector<string> result;
    int ROWS; int COLS;
    void insertWord(const string& word, int index) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i])
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->wordIndex = index; 
    }
    void dfs(vector<vector<char>>& board, int r, int c, 
    TrieNode* node, const vector<string>& words) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] == '#')
            return;
        char ch = board[r][c];
        TrieNode* nextNode = node->children[ch - 'a'];
        if (!nextNode)
            return;
        if (nextNode->wordIndex != -1) {
            result.push_back(words[nextNode->wordIndex]);
            nextNode->wordIndex = -1; 
        }
        board[r][c] = '#';
        dfs(board, r + 1, c, nextNode, words);
        dfs(board, r - 1, c, nextNode, words);
        dfs(board, r, c + 1, nextNode, words);
        dfs(board, r, c - 1, nextNode, words);
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
            insertWord(words[i], i);
        ROWS = board.size(); COLS = board[0].size();
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                // Minor optimization: only start DFS if 
                // the root has a child for this character
                if (root->children[board[r][c] - 'a'])
                    dfs(board, r, c, root, words);
            }
        }
        return result;
    }
};
