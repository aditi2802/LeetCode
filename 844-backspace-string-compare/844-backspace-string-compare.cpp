class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') s1 += s[i];
            else if(s[i]=='#'){
                if(!s1.empty()) s1.pop_back();
            }
        }
        for(int i = 0;i<t.size();i++){
            if(t[i]!='#') s2 += t[i];
            else if(t[i]=='#'){
                if(!s2.empty()) s2.pop_back();
            }
        }
        return (s1==s2);
    }
};