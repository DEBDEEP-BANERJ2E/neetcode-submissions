class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> countT, window;
        for (char c : t) countT[c]++;

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;
            if (countT.count(c) && window[c] == countT[c])
                have++;
            while (have == need) {
                if ((right - left + 1) < resLen) {
                    res = {left, right};
                    resLen = right - left + 1;
                }
                char leftChar = s[left];
                window[leftChar]--;
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
        
    }
};
