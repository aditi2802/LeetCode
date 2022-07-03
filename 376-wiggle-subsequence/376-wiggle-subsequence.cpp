class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = 1;
        int prevDiff = 0;
        int currDiff;
        for(int i=1;i<nums.size();i++){
            currDiff = nums[i]-nums[i-1];
            
            if(currDiff>0 && prevDiff<=0 || currDiff<0 && prevDiff>=0){
                len++;
                prevDiff = currDiff;
            }
        }
        return len;
    }
};