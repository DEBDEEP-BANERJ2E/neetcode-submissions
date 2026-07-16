class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> a;
        unordered_map<string, vector<string>> mp;

        for(string s : strs){
            string value = s;
            sort(s.begin(), s.end());
            mp[s].push_back(value);
        }

        for(auto pair : mp){
            res.push_back(pair.second);
        }
        return res;
    }
};
