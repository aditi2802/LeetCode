class Solution {
public:
    int lcs(int i,int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        //match
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1+lcs(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
    }
  
    int longestPalindromicSubsequ(string S1){
        string S2 = S1;
        reverse(S1.begin(), S1.end());
        int n = S1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return lcs(n-1, n-1, S1, S2, dp);
    }
    
    int minInsertions(string str) {
        int len = str.size();
        return len - longestPalindromicSubsequ(str);
    }
};