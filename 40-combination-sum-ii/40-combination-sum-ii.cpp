class Solution {
public:
    void helper(int index, int target, vector<int>&ds, vector<vector<int>>&ans, vector<int>arr){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i = index;i<arr.size();i++){
            if(i>index && arr[i-1]==arr[i]) continue;
            
            if(arr[i]>target) break;
            
            ds.push_back(arr[i]);
            target -= arr[i];
            helper(i+1, target, ds, ans, arr);
            ds.pop_back();
            target += arr[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, target, ds, ans, candidates);
        return ans;
    }
};