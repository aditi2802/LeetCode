class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans;
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(m[nums[i]]>n/2){
                ans = nums[i];
            }
        }
        return ans;
    }
};