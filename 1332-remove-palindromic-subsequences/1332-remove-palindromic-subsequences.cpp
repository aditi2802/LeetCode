class Solution {
public:
    int removePalindromeSub(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        if(s==rev) return 1;
        else return 2;
    }
};