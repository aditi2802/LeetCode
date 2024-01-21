class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0];
        int count = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i] == majority){
                count++;
            }
            else if (count==0){
                majority = nums[i];
                count = 1;
            }
            else count--;
        }
        return majority;
    }
};