class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n<=1) return "";
        
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i] = 'a';  //replace first non a character by a to break pal
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';  //if string has all a replace last a by b for smallest
        return palindrome;
    }
};