//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};
    
    vis[row][col] = 1;
    for(int i=0;i<4;i++){
        int nr = row+delr[i];
        int nc = col+delc[i];
        
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
            vis[nr][nc] = 1;
            dfs(nr, nc, vis, mat);
        }
    }
}
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        //traverse first and last row
        for(int j=0;j<m;j++){
            //first row
            if(mat[0][j]=='O' && !vis[0][j]) dfs(0,j,vis,mat);
            //last row
            if(mat[n-1][j]=='O' && !vis[n-1][j]) dfs(n-1,j,vis,mat);
        }
        
        //travserse first and last col
        for(int i=0;i<n;i++){
            //first col
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,vis,mat);
            //last col
            if(mat[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,vis,mat);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O') mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends