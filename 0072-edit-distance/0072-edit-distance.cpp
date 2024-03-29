class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
      if(i<0) return j+1;
      if(j<0) return i+1;
      if(dp[i][j]!=-1) return dp[i][j];
      
      //match
      if(s[i]==t[j]) return dp[i][j] = 0 + f(i-1, j-1, s, t, dp);
      
      return dp[i][j] = 1 + min(f(i, j-1, s, t, dp), min(f(i-1, j, s, t, dp), f(i-1, j-1, s, t, dp)));
  }
    
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, word1, word2, dp);
    }
};