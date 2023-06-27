//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int f(int n, int i, vector<int>&a, vector<vector<int>> &dp){
    if(i>=3 || n<0) return 0;
    if(n==0) return 1;
    if(dp[n][i]!=-1) return dp[n][i];
    long long int take = f(n-a[i], i, a, dp);
    long long int nottake = f(n, i+1, a, dp);
    
    return dp[n][i] = take+nottake;
}

long long int count(long long int n)
{
	vector<int> a(3);
	a[0] = 3;
	a[1] = 5;
	a[2] = 10;
	vector<vector<int>> dp(n+1, vector<int>(3, -1));
	return f(n, 0, a, dp);
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends