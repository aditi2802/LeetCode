class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy;
        copy=nums;
        sort(copy.begin(), copy.end());
        int low = INT_MAX;
        int high = INT_MIN;
        if(nums==copy) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=copy[i]){
                low = min(low, i);
                high = max(high, i);
            }
        }
        return high-low+1;
    }
};