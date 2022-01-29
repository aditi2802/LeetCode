class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
          if(s[i]>=65 || s[i]<=90){
            s[i] = tolower(s[i]);
          }
        }
        return s;
    }
};