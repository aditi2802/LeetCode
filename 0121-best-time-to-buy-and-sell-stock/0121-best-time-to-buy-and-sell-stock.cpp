class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxdiff = 0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini) mini = prices[i];
            maxdiff = max(prices[i]-mini, maxdiff);
        }
        return maxdiff;
    }
};