class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            maxSum = max(maxSum,currSum);
            if(currSum<0) currSum = 0;
        }
        
        currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            minSum = min(minSum,currSum);
            if(currSum>0) currSum = 0;
        }
        return max(maxSum,abs(minSum));
    }
};