class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int r = matrix.size();
        if(r==0) return v;
        int c = matrix[0].size();
        
        int top = 0, bottom = r-1;
        int left = 0, right = c-1;
        int dir = 0;
        
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                }
                dir = 1;
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    v.push_back(matrix[i][right]);
                }
                dir = 2;
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                dir = 3;
                bottom--;
            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]); 
                }
                dir = 0;
                left++;
            }
        }
        return v;
    }
};