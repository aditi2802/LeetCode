class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count = 0;
        unordered_map<int, int> hash;
        
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            hash[nums1[i]+nums2[j]]++;
          }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              count+=hash[-(nums3[i]+nums4[j])];
            }
        }
        return count;
    }
};