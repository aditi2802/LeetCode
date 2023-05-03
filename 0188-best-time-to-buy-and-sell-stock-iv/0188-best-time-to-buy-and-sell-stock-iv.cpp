class Solution {
private:
    int f(int i, int buyFlag, int n, vector<int>& prices, int k, vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(k==0) return 0;
        int profit = 0;
        if(dp[i][buyFlag][k]!=-1) return dp[i][buyFlag][k];
        if(buyFlag){
            int buy = -prices[i] + f(i+1, 0, n, prices, k, dp);
            int notBuy = 0 + f(i+1, 1, n, prices, k, dp);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[i] + f(i+1, 1, n, prices, k-1, dp);
            int notSell = 0 + f(i+1, 0, n, prices, k, dp);
            profit = max(sell, notSell);
        }
        return dp[i][buyFlag][k] = profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, n, prices, k, dp);
    }
};