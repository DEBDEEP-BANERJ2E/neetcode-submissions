class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> result;
        string current = "";
        vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        backtrack(digits, 0, current, result, pad);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, 
    vector<string>& result, const vector<string>& pad) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = pad[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result, pad);
            current.pop_back();
        }
    }
};
