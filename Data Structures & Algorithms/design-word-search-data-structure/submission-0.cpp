class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    TrieNode* root;
    
    // Helper function for DFS search
    bool searchInNode(const string& word, int index, TrieNode* node) {
        if (node == nullptr) return false;
// Base case: If we've reached the end of word, check if it's a valid end node
        if (index == word.length()) return node->isEndOfWord;
        char c = word[index];
        if (c != '.')
            // Standard character traversal
            return searchInNode(word, index + 1, node->children[c - 'a']);
        else {
            // Wildcard '.': Try all 26 possible branches
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] != nullptr && searchInNode(word, 
                index + 1, node->children[i]))
                    return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};
