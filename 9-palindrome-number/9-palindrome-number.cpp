class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        reverse(str.begin(), str.end());
        return str == to_string(x);
    }
};