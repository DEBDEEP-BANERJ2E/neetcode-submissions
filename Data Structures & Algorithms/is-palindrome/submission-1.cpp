class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        char *p1, *p2;
        p1=&s[0];
        p2=&s[s.length()-1];
        while(p1 < p2) {
            if(!isalnum(*p1)) {
                p1++; 
                continue;
            }
            if(!isalnum(*p2)) {
                p2--;
                continue;
            }
            if(tolower(*p1) != tolower(*p2)) {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};
