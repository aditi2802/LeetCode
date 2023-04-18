//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
	    if(i<0 || j<0) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(s1[i]==s2[j]) return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
	    
	    return dp[i][j] = max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1 = str1.size();
	    int n2 = str2.size();
	    //total operations = deletion + insertion
	    //deletion = n1 - len of lcs
	    //insertion = n2 - len of lcs
	    vector<vector<int>> dp(n1, vector<int>(n2, -1));
	    int lenOflcs = lcs(n1-1, n2-1, str1, str2, dp);
	    
	    return n1+n2-2*lenOflcs;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends