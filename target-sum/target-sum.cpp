class Solution {
public:
    int f(int i, int sum, vector<int>&nums, vector<vector<int>> &dp){
        if(i==0){
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0 || sum==nums[0]) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notpick = f(i-1, sum, nums, dp);
        int pick = 0;
        if(nums[i]<=sum) pick = f(i-1, sum-nums[i], nums, dp);
        
        return dp[i][sum] = pick+notpick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if((total-target)<0 || (total-target)%2==1) return 0;
        
        int k = (total-target)/2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1, k, nums, dp);
    }
};