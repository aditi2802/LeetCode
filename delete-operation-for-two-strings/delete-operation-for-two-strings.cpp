class Solution {
public:
    int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
	    if(i<0 || j<0) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(s1[i]==s2[j]) return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
	    
	    return dp[i][j] = max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
	}
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
	    int n2 = word2.size();
	    //total operations = deletion + insertion
	    //deletion = n1 - len of lcs
	    //deletion = n2 - len of lcs
	    vector<vector<int>> dp(n1, vector<int>(n2, -1));
	    int lenOflcs = lcs(n1-1, n2-1, word1, word2, dp);
	    
	    return n1+n2-2*lenOflcs;
    }
};