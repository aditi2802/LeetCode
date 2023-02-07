//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    private:
    void dfs(int i, int j, vector<vector<int>> &vis, string s, vector<vector<int>> &m, int n){
        if(i<0 || j<0 || i>=n || j>=n) return; //boundary condition
        if(m[i][j]==0 || vis[i][j]==1) return; //if pos is blocked or already vis
        
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        vis[i][j] = 1;
        dfs(i-1, j, vis, s+"U", m, n);
        dfs(i+1, j, vis, s+"D", m, n);
        dfs(i, j-1, vis, s+"L", m, n);
        dfs(i, j+1, vis, s+"R", m, n);
        
        vis[i][j] = 0; //while backtrack mark it unvis
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if(m[0][0]==0) return ans;
        if(m[n-1][n-1]==0) return ans;
        
        dfs(0, 0, vis, s, m, n);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends