class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        queue<pair<pair<int, int>, int>>q;
        
        int freshcnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1) freshcnt++;
            }
        }
        
        int maxt = 0;
        int rtncnt = 0;
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxt = max(maxt, t);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && 
                   grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                    rtncnt++;
                }
            }
        }
        if(freshcnt!=rtncnt) return -1;
        return maxt;
    }
};