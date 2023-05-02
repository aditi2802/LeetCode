class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        
        for(int i=0;i<prices.size();i++){
            int profit = prices[i] - mini;
            maxProfit = max(profit, maxProfit);
            mini = min(prices[i], mini);
        }
        return maxProfit;
    }
};