class Solution {
public:

    string encode(vector<string>& strs) {
        string en="";
        for(string s : strs){
            en+= to_string(s.size())+"#"+s;
        }
        return en;
    }

    vector<string> decode(string str) {
        vector<string> res;
        int i=0;
        int c=0;
        string s=""; string p="";
        while(i < str.size()){
            char t=str[i];
            if(t!='#'){
                s+=t;
                i++;
            }
            if(t=='#'){
                i++;
                c=stoi(s);
                while(c>0){
                    p+=str[i];
                    c--;
                    i++;
                }
                res.push_back(p);
                s=""; p="";
            }
        }
        return res;
    }
};
