class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotIndex = -1;
        
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pivotIndex = i-1;
                break;
            }
        }
        
        if(pivotIndex==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[pivotIndex]){
                swap(nums[i], nums[pivotIndex]);
                reverse(nums.begin()+pivotIndex+1, nums.end());
                break;
            }
        }
    }
};