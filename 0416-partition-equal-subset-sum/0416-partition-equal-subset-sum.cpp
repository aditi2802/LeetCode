class Solution {
public:
    bool f(int i, int k, vector<int>& nums, vector<vector<int>> &dp){
        if(k==0) return true;
        if(i==0){
            if(nums[0]==k) return true;
            return false;
        }
        if(dp[i][k]!=-1) return dp[i][k]; 
        bool nottake = f(i-1, k, nums, dp);
        bool take = false;
        if(nums[i]<=k) take = f(i-1, k-nums[i], nums, dp);
        
        return dp[i][k] = take||nottake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        
        if(sum%2==1) return false;
        else{
            int k = sum/2;
            vector<vector<int>> dp(n, vector<int>(k+1, -1));
            return f(n-1, k, nums, dp);
        }
    }
};