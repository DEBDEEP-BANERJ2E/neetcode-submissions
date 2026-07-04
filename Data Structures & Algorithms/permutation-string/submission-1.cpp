class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        sort(s1.begin(), s1.end());
        if(n>m) return false;
        else if(n==m){
            sort(s2.begin(), s2.end());
            return s1==s2;
        } 
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        for (int i = 0; i < m - n; i++) {
            if (s1Count == s2Count) return true;

            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + n] - 'a']++;
        }
        return s1Count == s2Count;
    }
};
