class Solution {
public:
    int f(int i, int sum, vector<int>&coins, vector<vector<int>> &dp){
        if(i==0){
            if(sum%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notpick = f(i-1, sum, coins, dp);
        int pick = 0;
        if(coins[i]<=sum) pick = f(i, sum-coins[i], coins, dp);
        
        return dp[i][sum] = (pick+notpick);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};