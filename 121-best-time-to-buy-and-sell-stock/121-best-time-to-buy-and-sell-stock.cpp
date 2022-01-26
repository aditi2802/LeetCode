class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int currprofit = 0 ;
        for(int i=1;i<prices.size();i++){
          currprofit+= prices[i] - prices[i-1];
          if(currprofit<0){
            currprofit = 0;
          }
            if(currprofit>max){
              max = currprofit;
            }
        }
        return max;
    }
};