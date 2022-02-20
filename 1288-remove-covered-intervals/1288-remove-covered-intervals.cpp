class Solution {
public:
    static bool mysort(vector<int>&v1, vector<int>&v2){
          if(v1[0]==v2[0]){
            return v1[1]>v2[1];
          }
            else{
                return v1[0]<v2[0];
            }
        }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), mysort);
        int ans = 0;
        int start = intervals[0][0], end = intervals[0][1];

        
        if(n==1) return 1;
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=start && intervals[i][1]<=end){
                ans++;
            }
            else{
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return n-ans;
    }
};