class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s<=e){
            if(nums[s]<nums[e]) return nums[s];
            int m = s+(e-s)/2;
            int next = (m+1)%n;
            int prev = (m+n-1)%n;
            
            if(nums[m]<=nums[prev] && nums[m]<=nums[next]) return nums[m];
            else if(nums[s]<=nums[m]) s = m+1;
            else e = m-1;
        }
        return -1;
    }
};