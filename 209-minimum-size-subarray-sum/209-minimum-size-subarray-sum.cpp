class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int mini = INT_MAX;
        
        while(j<n){
            while(sum<target && j<n){
                sum += nums[j];
                j++;
            }
            while(sum>=target && i<n){
                mini = min(mini, (j-i));
                sum -= nums[i];
                i++;
            }
        }
        if(mini==INT_MAX) return 0;
        else return mini;
    }
};