class Solution {
private:
void bfs(int r,int c,int m,int n,vector<vector<int>>&vis,vector<vector<char>>&grid,int delr[],int delc[]){
    vis[r][c] = 1;
    queue<pair<int,int>>q;
    q.push({r,c});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
             if(nr>=0 && nr<m && nc>=0 && nc<n &&
                  !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
        }
    }
}
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,m,n,vis,grid,delr,delc);
                }
            }
        }
        return count;
    }
};