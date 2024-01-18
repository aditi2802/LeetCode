class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // //Approach1 brute force, tc:O(nlogn+n) sc:0(1)
        // int ans;
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<n-1;i++){
        //     if(nums[i] == nums[i+1]) ans = nums[i];
        // }
        // return ans;
        
        //Approach2 optimal, tc:o(n), sc: o(n)
        int ans;
        int n = nums.size();
        vector<int> freq(n+1,0);
        
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0) freq[nums[i]]++;
            else return nums[i];
        }
        return 0;
    }
};