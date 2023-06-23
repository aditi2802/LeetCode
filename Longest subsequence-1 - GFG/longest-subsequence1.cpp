//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int prev, int n, int a[], vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take = 0;
        if(prev==-1 || abs(a[i]-a[prev])==1) take = 1 + f(i+1, i, n, a, dp);
        
        int nottake = f(i+1, prev, n, a, dp);
        
        return dp[i][prev+1] = max(take, nottake);
    }

    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(0, -1, N, A, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends