class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        
        int ans;
        while(s<=e){
            int m = s+(e-s)/2;
            if(m<=x/m){    //m*m=x
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        return ans;
    }
};