class Solution {
public:
    string reverseWords(string s) {
        int start = 0; //to track start of a word
        for(int i=0;i<s.size();i++){
          if(s[i]==' '){
            reverse(s.begin()+start, s.begin()+i);
             start = i+1;
          }
        }
        reverse(s.begin()+start, s.end()); //for last word in sentence
        return s;
    }
};