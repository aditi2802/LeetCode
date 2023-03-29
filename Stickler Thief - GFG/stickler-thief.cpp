//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    //Recursion
    /*int f(int arr[], int i){
        if(i==0) return arr[0];
        if(i<0) return 0;
        int pick = arr[i] + f(arr, i-2);
        int notpick = 0 + f(arr, i-1);
        return max(pick, notpick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return f(arr, n-1);
    }*/
    
    //Memoization
    /*int f(int arr[], int i, vector<int>& dp){
        if(i==0) return arr[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = arr[i] + f(arr, i-2, dp);
        int notpick = 0 + f(arr, i-1, dp);
        dp[i] = max(pick, notpick);
        return dp[i];
    }
    
    int FindMaxSum(int arr[], int n){
        vector<int> dp(n+1, -1);
        return f(arr, n-1, dp);
    }*/
    
    //Tabulation without space optimisarion
    /*int FindMaxSum(int arr[], int n){
        vector<int> dp(n+1, -1);
        dp[0] = arr[0];
        for(int i=1;i<n+1;i++){
            int pick = arr[i];
            if(i>1) pick += dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }*/
    
    //Tabulation with space optimisation
    int FindMaxSum(int arr[], int n){
        int prev = arr[0];
        int prev2 = 0;
        for(int i=0;i<n;i++){
            int pick = arr[i];
            if(i>1) pick += prev2;
            int notpick = 0 + prev;
            int curri = max(pick, notpick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends