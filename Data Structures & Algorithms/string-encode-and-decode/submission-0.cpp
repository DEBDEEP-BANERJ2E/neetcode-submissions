class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string str) {
        vector<string> output;
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '#') j++;
            int length = stoi(str.substr(i, j - i));
            i = j + 1;
            output.push_back(str.substr(i, length));
            i += length;
        }
        return output;
    }
};