//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int i, int amount, vector<int>&nums, vector<vector<int>> &dp){
	    if(i==0){
	        if(amount%nums[0]==0) return amount/nums[0];
	        return 1e9;
	    }
	    if(dp[i][amount]!=-1) return dp[i][amount];
	    int notpick = f(i-1, amount, nums, dp);
	    int pick = INT_MAX;
	    if(nums[i]<=amount) pick = 1+f(i, amount-nums[i], nums, dp);
	    
	    return dp[i][amount] = min(pick, notpick);
	}
	
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n = nums.size();
	    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
	    
	    int ans = f(n-1, amount, nums, dp);
	    if(ans==1e9) return -1;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends