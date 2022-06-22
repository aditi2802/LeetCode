class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minElement = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            minElement = min(minElement,prices[i]);
            maxProfit = max(maxProfit,(prices[i]-minElement));
        }
        return maxProfit;
    }
};