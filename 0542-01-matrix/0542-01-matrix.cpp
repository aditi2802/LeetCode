class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dis(m, vector<int>(n,0));
        queue<pair<pair<int,int>, int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dis[r][c] = steps;
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return dis;
    }
};