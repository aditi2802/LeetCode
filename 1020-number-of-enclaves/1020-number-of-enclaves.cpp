class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1){
                      q.push({i,j});
                      vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }
        return count;
    }
};