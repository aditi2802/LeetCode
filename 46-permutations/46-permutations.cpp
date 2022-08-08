class Solution {
public:
    void helper(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i], nums[index]);
            helper(nums, index+1, ans);
            swap(nums[i], nums[index]); //backtrack to get string before swap
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};