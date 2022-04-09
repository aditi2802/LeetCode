class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]<nums[i] && nums[i+1]<nums[i]){
                return i;
            }
        }
        return -1;
    }
};