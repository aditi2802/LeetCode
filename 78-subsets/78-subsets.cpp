class Solution {                          // https://www.youtube.com/watch?v=6BPurabdAl4
public:
    void help(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
       if(i==nums.size()){
          ans.push_back(temp);
       }
        else{
            temp.push_back(nums[i]);   //either consider ith element
            help(i+1, nums, ans, temp);
            
            temp.pop_back();           //or ignore it
            help(i+1, nums, ans, temp);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(0, nums, ans, temp);
        return ans;
    }
};