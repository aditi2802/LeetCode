//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int k, int arr[], vector<vector<int>> &dp){
        if(k==0) return 1;
        if(i==0) return arr[0]==k;
        if(dp[i][k]!=-1) return dp[i][k];
        int nottake = f(i-1, k, arr, dp);
        int take = 0;
        if(arr[i]<=k) take = f(i-1, k-arr[i], arr, dp);
        
        return dp[i][k] = take||nottake;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum = 0;
        for(int i=0;i<N;i++) sum+= arr[i];
        if(sum%2==1) return 0;
        else{
            int k = sum/2;
            vector<vector<int>> dp(N, vector<int>(k+1, -1));
            return f(N-1, k, arr, dp);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends