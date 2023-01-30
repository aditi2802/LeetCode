class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&board){
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr, nc, vis, board);
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        //traverse boundaries
        for(int j=0;j<n;j++){
            //first row
            if(board[0][j]=='O' && !vis[0][j]) dfs(0, j, vis, board);
            //last row
            if(board[m-1][j]=='O' && !vis[m-1][j]) dfs(m-1, j, vis, board);
        }
        
        for(int i=0;i<m;i++){
            //first col
            if(board[i][0]=='O' && !vis[i][0]) dfs(i, 0, vis, board);
            //last col
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(i, n-1, vis, board);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
            }
        }
        
    }
};