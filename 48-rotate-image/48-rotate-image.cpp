class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m/2; i++){
            for(int j=i; j<m-i-1; j++){
                swap(matrix[i][j], matrix[m-1-j][i]);
                swap(matrix[j][m-1-i], matrix[m-1-i][m-1-j]);
                swap(matrix[m-1-j][i], matrix[j][m-1-i]);
            }
        }

    }
};