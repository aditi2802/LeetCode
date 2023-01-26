class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int iniclr,
            vector<vector<int>>& ans, int delr[], int delc[]){
        int n = image.size();
        int m = image[0].size();
        ans[r][c] = color;
        
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && 
               image[nr][nc]==iniclr && ans[nr][nc]!=color)
                dfs(image, nr, nc, color, iniclr, ans, delr, delc);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniclr = image[sr][sc];
        vector<vector<int>> ans = image;
        int delr[] = {0,-1,0,1};
        int delc[] = {-1,0,1,0};
        dfs(image,sr,sc,color,iniclr,ans,delr,delc);
        return ans;
    }
};