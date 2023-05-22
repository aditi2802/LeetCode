class Solution {
private:
    //Using Binary Search
    public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            
            else{
                auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);
                *ind = nums[i];
            }
        }
        return temp.size();
    }
    
    /* Using DP
    int f(int i, int previ, int n, vector<int>& nums, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][previ+1]!=-1) return dp[i][previ+1];
        int notTake = 0 + f(i+1, previ, n, nums, dp);
        int take = 0;
        if(previ==-1 || nums[i]>nums[previ]) take = 1 + f(i+1, i, n, nums, dp);
        
        return dp[i][previ+1] = max(take, notTake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, n, nums, dp);
    }*/
};