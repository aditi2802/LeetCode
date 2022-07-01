class Solution {
public:
    static bool compare(vector<int>& a, vector<int> &b){
        if(a[1]>b[1]) return true;
        return false;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int ans = 0;
        
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<truckSize){
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                int canTake = truckSize;
                truckSize -= canTake;
                ans += canTake*boxTypes[i][1];
            }
        }
        return ans;
    }
};