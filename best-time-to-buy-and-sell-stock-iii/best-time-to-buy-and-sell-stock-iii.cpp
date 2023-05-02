class Solution {
private:
    int f(int i, int buyFlag, int noOfTrans, vector<int>& prices, int n, vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(noOfTrans==0) return 0;
        int profit = 0;
        if(dp[i][buyFlag][noOfTrans]!=-1) return dp[i][buyFlag][noOfTrans];
        if(buyFlag){
            int buy = -prices[i] + f(i+1, 0, noOfTrans, prices, n, dp);
            int notBuy = 0 + f(i+1, 1, noOfTrans, prices, n, dp);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[i] + f(i+1, 1, noOfTrans-1, prices, n, dp);
            int notSell = 0 + f(i+1, 0, noOfTrans, prices, n, dp);
            profit = max(sell, notSell);
        }
        return dp[i][buyFlag][noOfTrans] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, n, dp);
    }
};