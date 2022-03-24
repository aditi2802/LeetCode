class Solution {
public:
    bool ispal(string s){
        string original = s;
        reverse(s.begin(), s.end());
        if(original == s) return true;
        return false;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(ispal(words[i])){
                return words[i];
            }
        }
        return "";
    }
};