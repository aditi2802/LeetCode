class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        int area_xy = 0;
        for (int y = 0; y < m; y++){
            for (int x = 0; x < n; x++){
                if (grid[y][x] > 0){
                    area_xy++;
                }
            }
        }
        int area_yz = 0;
        for (int y = 0; y < m; y++){
            int tallest = 0;
            for (int x = 0; x < n; x++){
                tallest = max(tallest, grid[y][x]);
            }
            area_yz += tallest;
        }
        int area_xz = 0;
        for (int x = 0; x < n; x++){
            int tallest = 0;
            for (int y = 0; y < n; y++){
                tallest = max(tallest, grid[y][x]);
            }
            area_xz += tallest;
        }
        return area_xy + area_yz + area_xz;
    }
};