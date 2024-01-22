class Solution {
public:
    //Recursive
    // int helper(int i, int j, int m, int n){
    //     if(i>=m || j>=n) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     int right = helper(i, j+1, m, n);
    //     int down = helper(i+1, j, m, n);
    //     return right+down;
    // }
    
    // int uniquePaths(int m, int n) {
    //     return helper(0, 0, m, n);
    // }
    
    //dp solution
    int helper(int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = helper(i, j-1, dp);
        int down = helper(i-1, j, dp);
        return dp[i][j] = right+down;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(m-1, n-1, dp);
    }
};