class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int violation = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                violation++;
                
                if(violation>1) return false;
                
                if(i==1 || nums[i-2]<=nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;;
    }
};