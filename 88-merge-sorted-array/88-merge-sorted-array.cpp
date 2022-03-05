class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);  //nums1=[1,2,3]
        nums1.insert(nums1.end(), nums2.begin(), nums2.end()); //nums1=[1,2,3,2,5,6]
        sort(nums1.begin(), nums1.end()); //[1,2,2,3,5,6]
        return;
    }
};