//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue <pair <pair<int, int>, int >> q;  // ({r,c}, t)
        int freshcnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                } 
                if(grid[i][j]==1) freshcnt++;
            }
        }
        
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        int rottencnt = 0;
        int t;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            t = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({{nr,nc}, t+1});
                    vis[nr][nc] = 2;
                    rottencnt++;
                }
            }
        }
        if(rottencnt!=freshcnt) return -1;
        return t;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends