class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        queue<pair<int,pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<8;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                  grid[nr][nc]==0 && 1+dis<dist[nr][nc]){
                    dist[nr][nc] = 1+dis;
                    q.push({1+dis, {nr, nc}});
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return 1+dist[n-1][n-1];
    }
};