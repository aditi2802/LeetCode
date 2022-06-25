class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(auto it : mp){
            if(it.second>(n/3)){
                v.push_back(it.first);
            }
        }
        return v;
    }
};