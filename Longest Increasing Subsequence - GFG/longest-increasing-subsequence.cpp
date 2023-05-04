//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    int f(int i, int previ, int n, int a[], vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][previ+1]!=-1) return dp[i][previ+1];
        int notTake = 0 + f(i+1, previ, n, a, dp);
        int take = 0;
        if(previ==-1 || a[i]>a[previ])  take = 1 + f(i+1, i, n, a, dp);
        
        return dp[i][previ+1] = max(notTake, take);
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n, vector<int>(n+1, -1)); //previ is from -1 to n-1 since we cant store neg value in dp matrix hence doing coordinate change i.e 0 to n so n+1
       return f(0, -1, n, a, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends