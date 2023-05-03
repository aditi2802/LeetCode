//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long f(int i, int buyFlag, int n, vector<long long>&prices, int fee, vector<vector<long long>> &dp){
        if(i==n) return 0;
        long long profit = 0;
        if(dp[i][buyFlag]!=-1) return dp[i][buyFlag];
        if(buyFlag){
            long long buy = -prices[i] + f(i+1, 0, n, prices, fee, dp);
            long long notbuy = 0 + f(i+1, 1, n, prices, fee, dp);
            profit = max(buy, notbuy);
        }
        else{
            long long sell = prices[i] + f(i+1, 1, n, prices, fee, dp) - fee;
            long long notsell = 0 + f(i+1, 0, n, prices, fee, dp);
            profit = max(sell, notsell);
        }
        return dp[i][buyFlag] = profit;
    }
    
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, 1, n, prices, fee, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends