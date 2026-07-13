class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Quickly check if endWord is even in the list
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        unordered_map<string, vector<string>> adj;
        // Add beginWord to the list so we build patterns for it as well
        wordList.push_back(beginWord); 
        
        // 1. Build the adjacency list using wildcards
        for (const string& word : wordList) {
            for (int i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';
                adj[pattern].push_back(word);
            }
        }
        
        // 2. BFS initialization
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int res = 1;
        
        // 3. Traverse level by level
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) return res;
                
                // Find all neighbors using the wildcard patterns
                for (int j = 0; j < word.length(); ++j) {
                    string pattern = word;
                    pattern[j] = '*';
                    for (const string& neighbor : adj[pattern]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            // Increment the path length after finishing the current level
            res++;
        }
        return 0;
    }
};
