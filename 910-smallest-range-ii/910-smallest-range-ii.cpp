class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size()-1]-nums[0];
        int smallest = nums[0]+k;
        int largest = nums[nums.size()-1]-k;
        for(int i=0;i<nums.size()-1;i++){
            int mini = nums[i+1]-k;
            int maxi = nums[i]+k;
            mini = min(mini,smallest);
            maxi = max(maxi,largest);
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};