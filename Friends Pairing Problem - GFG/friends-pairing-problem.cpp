//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    long long int f(int n, vector<int> &dp){
        int mod = 1e9 + 7;
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        long long int single = 1*f(n-1, dp);
        long long int pair = (n-1)*f(n-2, dp);
        
        return dp[n] = (single+pair) % mod;
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends