class Solution {
public:
    char findTheDifference(string s, string t) {
        int sums = 0;
        int sumt = 0;
        for(int i=0;i<s.size();i++){
         sums+=s[i];
         sumt+=t[i];
        }
        sumt+=t[t.size()-1];   //as length of t is one more than s
        return char(sumt-sums);
    }
};