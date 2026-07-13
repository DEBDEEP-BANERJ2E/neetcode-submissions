class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        // 1. Initialize adjacency list with every unique 
        // character in the dictionary
        for (const string& word : words) {
            for (char c : word)
                adj[c] = unordered_set<char>();
        }
        // 2. Build the graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            // Invalid condition: a longer prefix comes before a shorter one
            if (w1.length() > w2.length() && 
            w1.substr(0, minLen) == w2.substr(0, minLen))
                return "";
            // Find the first differing character to establish relative order
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break; // Only the first difference dictates the ordering
                }
            }
        }
        // Map to keep track of visited nodes 
        // (true = visiting, false = visited)
        unordered_map<char, bool> visited;
        string result = "";
        // 3. Perform DFS to build topological sort
        for (const auto& pair : adj) {
            if (dfs(pair.first, adj, visited, result))
                return ""; // Cycle detected, no valid ordering
        }
        // 4. Reverse the post-order result to get the actual topological order
        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool dfs(char node, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, bool>& visited, string& result) {
        // If node is already in the map, check its status
        if (visited.find(node) != visited.end())
            return visited[node]; // true implies cycle, false implies safe
        // Mark as currently visiting
        visited[node] = true;
        // Visit all neighbors
        for (char neighbor : adj[node]) {
            if (dfs(neighbor, adj, visited, result)) return true;
        }
        // Mark as fully processed (safe)
        visited[node] = false; result += node; // Append in post-order
        return false;
    }
};
