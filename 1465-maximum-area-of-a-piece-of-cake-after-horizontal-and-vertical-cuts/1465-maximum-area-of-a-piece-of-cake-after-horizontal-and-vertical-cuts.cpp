class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxi1 = 0;
        int maxi2 = 0;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            maxi1 = max(maxi1, horizontalCuts[i+1]-horizontalCuts[i]);
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            maxi2 = max(maxi2, verticalCuts[i+1]-verticalCuts[i]);
        }
        
        return ((long)maxi1 * (long)maxi2) % 1000000007;
    }
};