class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalsum = (n*(n+1))/2;
        
        int arraysum = 0;
        for(int i=0;i<nums.size();i++){
            arraysum+=nums[i];
        }
        return totalsum - arraysum;
    }
};