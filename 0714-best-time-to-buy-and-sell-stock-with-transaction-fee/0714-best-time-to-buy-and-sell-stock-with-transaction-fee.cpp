class Solution {
private:
    int f(int i, int buyFlag, int n, vector<int>& prices, int fee, vector<vector<int>> &dp){
        if(i==n) return 0;
        int profit = 0;
        if(dp[i][buyFlag]!=-1) return dp[i][buyFlag];
        if(buyFlag){
            int buy = -prices[i] + f(i+1, 0, n, prices, fee, dp);
            int notbuy = 0 + f(i+1, 1, n, prices, fee, dp);
            profit = max(buy, notbuy);
        }
        else{
            int sell = prices[i] + f(i+1, 1, n, prices, fee, dp) - fee;
            int notsell = 0 + f(i+1, 0, n, prices, fee, dp);
            profit = max(sell, notsell);
        }
        return dp[i][buyFlag] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, fee, dp);
    }
};