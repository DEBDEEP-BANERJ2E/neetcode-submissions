class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int l=0;
        int length=0;
        int freq=0;
        for(int i=0; i<s.size(); i++){
            v[(int)(s[i]-'A')]++;

            freq=max(freq, v[(int)(s[i]-'A')]);
            while ((i - l + 1) - freq > k) {
                v[(int)(s[l] - 'A')]--;
                l++;
            }

            length = max(length, i - l + 1);

        }
        return length;
    }
};
