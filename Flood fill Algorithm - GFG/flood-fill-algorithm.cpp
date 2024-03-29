//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
void dfs(int r, int c, int initialColor, int delr[], int delc[],
vector<vector<int>>&ans, vector<vector<int>>&image, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    ans[r][c] = newColor;
    
    for(int i=0;i<4;i++){
        int nr = r+delr[i];
        int nc = c+delc[i];
        
        if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initialColor && ans[nr][nc]!=newColor){
            dfs(nr,nc,initialColor,delr,delc,ans,image,newColor);
        }
    }
}
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        dfs(sr, sc, initialColor, delr, delc, ans, image, newColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends