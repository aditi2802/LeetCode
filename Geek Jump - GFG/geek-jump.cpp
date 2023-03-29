//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //Recursion
    /*int f(vector<int>& h, int i){
        if(i==0) return 0;
        int left = f(h, i-1) + abs(h[i]-h[i-1]);
        int right = INT_MAX;
        if(i>1) right = f(h, i-2) + abs(h[i]-h[i-2]);
        return min(left,right);
    }
  
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        return f(h, n-1);
    }*/
    
    //Memoization
    /*int f(vector<int>& h, vector<int>&dp, int i){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left = f(h, dp, i-1) + abs(h[i]-h[i-1]);
        int right = INT_MAX;
        if(i>1) right = f(h, dp, i-2) + abs(h[i]-h[i-2]);
        dp[i] = min(left, right);
        return dp[i];
    }
    
    int minimumEnergy(vector<int>& h, int n){
        
    }
        vector<int> dp(n+1, -1);
        return f(h, dp, n-1);
    }*/
    
    //Tabulation
    int minimumEnergy(vector<int>& h, int n){
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for(int i=1;i<n+1;i++){
            int left = dp[i-1] + abs(h[i]-h[i-1]);
            int right = INT_MAX;
            if(i>1) right = dp[i-2] + abs(h[i]-h[i-2]);
            dp[i] = min(left, right);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends