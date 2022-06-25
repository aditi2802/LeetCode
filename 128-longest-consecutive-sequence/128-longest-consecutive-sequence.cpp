class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxi = 1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1){
                count++;
                maxi = max(count, maxi);
            }
            else if(nums[i+1]==nums[i]){
                count = count;
            }
            else{
                count = 1;
            }
        }
        return maxi;
    }
};