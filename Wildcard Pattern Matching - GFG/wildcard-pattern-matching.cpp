//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  private:
  int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
      if(i<0 && j<0) return 1;
      if(i<0 && j>=0) return 0;
      if(i>=0 && j<0){
          for(int k=0;k<=i;k++){
              if(s[k]!='*') return 0;
          }
          return 1;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s[i]==t[j] || s[i]=='?') return dp[i][j] = f(i-1, j-1, s, t, dp);
      
      if(s[i]=='*') return dp[i][j] = f(i-1, j, s, t, dp) || f(i, j-1, s, t, dp);
  }
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends