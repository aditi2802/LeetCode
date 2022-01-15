class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int fmax = INT_MIN;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){ 
         sum+=nums[i];
         fmax = max(sum, fmax);
         
        if(sum<0){
          sum = 0;
        }
        }
        return fmax;
    }
};