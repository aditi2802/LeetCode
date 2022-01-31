class Solution {
public:
    bool isPalindrome(string s) {
        string res1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.size();i++){
          if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
             res1+=s[i];
          }
        }
        
        string res2 = res1;
        reverse(res2.begin(), res2.end());
        if(res1==res2){
         return true;
        }
        else{
         return false;
        }
    }
};