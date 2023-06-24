class Solution {
public:
    int f(int i, int prev, vector<vector<int>>& pairs, int n, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take = 0;
        if(prev==-1 || pairs[i][0]>pairs[prev][1]) take = 1 + f(i+1, i, pairs, n, dp);
        
        int nottake = f(i+1, prev, pairs, n, dp);
        
        return dp[i][prev+1] = max(take, nottake);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, -1, pairs, n, dp);
    }
};