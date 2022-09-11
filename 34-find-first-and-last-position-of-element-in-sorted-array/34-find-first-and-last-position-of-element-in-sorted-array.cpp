class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        vector<int> v(2, -1);
        
        //first occurence
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target){
                v[0] = m;
                e = m-1;
            }
            else if(nums[m]>target) e = m-1;
            else s = m+1;
        }
        
        //last occurence
        s = 0;
        e = nums.size()-1;
        
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target){
                v[1] = m;
                s = m+1;
            }
            else if(nums[m]>target) e = m-1;
            else s = m+1;
        }
        return v;
    }
};