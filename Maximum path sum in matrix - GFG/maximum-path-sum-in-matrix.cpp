//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int n, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
        if(j<0 || j>=n) return INT_MIN;
        if(i==0) return Matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int move1 = Matrix[i][j] + f(i-1, j, n, Matrix, dp);
        int move2 = Matrix[i][j] + f(i-1, j+1, n, Matrix, dp);
        int move3 = Matrix[i][j] + f(i-1, j-1, n, Matrix, dp);
        return dp[i][j] = max(move1, max(move2, move3));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int maxi = INT_MIN;
        for(int j=0;j<N;j++){  //we will calculate for all columns
           int ans = f(N-1, j, N, Matrix, dp); 
           maxi = max(maxi,ans);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends