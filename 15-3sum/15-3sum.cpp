class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.empty()) return v;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
                
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int start = i+1;
            int end = n-1;
            
            while(start<end){
                int sum = nums[i]+nums[start]+nums[end];
                if(sum>0) end--;
                else if(sum<0) start++;
                else{
                    v.push_back({nums[i], nums[start], nums[end]});
                    
                    int lasts = nums[start], laste = nums[end];
                    while(start<end && nums[start]==lasts) start++;  //handling duplicacy
                    while(start<end && nums[end]==laste) end--;
                }
            }
        }
        return v;
    }
};