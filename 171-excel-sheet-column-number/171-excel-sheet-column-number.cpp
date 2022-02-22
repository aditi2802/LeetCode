class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i=0;i<columnTitle.size();i++){
           int alpha = columnTitle[i]-'A'+1;        //AB = 1*26 + 2 = 28
            ans = ans*26 + alpha;                   // ABC = 1*26*26 + 2*26 + 3
        }
        return ans;
    }
};