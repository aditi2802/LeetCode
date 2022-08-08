class Solution {
public:
    void helper(string s, int i, vector<string>&ans){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        
        if(isalpha(s[i])){
            s[i] = toupper(s[i]);
            helper(s, i+1, ans);
            s[i] = tolower(s[i]);
            helper(s, i+1, ans);
        }
        else{
            helper(s, i+1, ans);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(s, 0, ans);
        return ans;
    }
};