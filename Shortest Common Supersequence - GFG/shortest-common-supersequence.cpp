//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int f(int i, int j, string &s1,string &s2, vector<vector<int>> &dp){
      if(i<0 || j<0) return 0;
      
      
      if(dp[i][j]!=-1) return dp[i][j];
      if(s1[i]==s2[j]) return dp[i][j] = 1+f(i-1, j-1, s1, s2, dp);
      
      return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
  }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        
        //code here
        vector<vector<int>> dp(101, vector<int>(101, -1));
        int lenOfLcs = f(m-1, n-1, X, Y, dp);
        return (m + n) - lenOfLcs;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends