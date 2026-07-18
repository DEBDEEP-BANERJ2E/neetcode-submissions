class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for(string i : strs){
            string val = i;
            sort(i.begin(), i.end());
            map[i].push_back(val);
        }

        for(auto pair : map){
            res.push_back(pair.second);
        }
        return res;
    }
};
