class Solution {
public:
    int scoreOfParentheses(string s) {
        int open = 0;
        int score = 0;
        
        for(int i=0;i<s.size();i++){
           if(s[i]=='('){
               open++;
           }
            else{
                open--;
                
                if(s[i-1]=='(' && s[i]==')'){
                    score += pow(2, open);
                }
            }
        }
        return score;
    }
};