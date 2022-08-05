class Solution {
public:
    void helper(int index, int target, vector<int>&ds, vector<vector<int>>&ans, vector<int>&arr){
        if(index==arr.size()){
            if(target==0) ans.push_back(ds);   //base case
        return;                                //backtrack
        } 
        
        //pick element
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            target -= arr[index];
            helper(index, target, ds, ans, arr);
            ds.pop_back();
            target += arr[index];
        }
        
        //not pick
        helper(index+1, target, ds, ans, arr);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, target, ds, ans, candidates);
        return ans;
    }
};