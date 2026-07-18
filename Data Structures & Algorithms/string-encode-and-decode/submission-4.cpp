class Solution {
// #define delimiter '\x1f'
public:

    string encode(vector<string>& strs) {
        char delimiter= '\x1f';
        string en="";
        for(string s : strs){
            en+= s + delimiter;
        }
        return en;
    }

    vector<string> decode(string s) {
        char delimiter= '\x1f';
        string str="";
        vector<string> res;
        for(char ch : s){
            if(ch != delimiter){
                str+=ch;
            }
            else{
                res.push_back(str);
                str="";
            }
        }
        return res;
    }
};
