class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(needle.size()>haystack.size());
        int ans = haystack.find(needle);
        return ans;
    }
};