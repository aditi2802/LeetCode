//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
    
    return dp[i][j] = max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
}

int longestPalinSubseq(string s1){
    int n = s1.size();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return lcs(n-1, n-1, s1, s2, dp);
}
  
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.size();
        return n - longestPalinSubseq(S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends