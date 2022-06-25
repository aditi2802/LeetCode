class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);         //to remove duplicates
        }
        
        int longLen = 0; //to keep track of longest subseq
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end()){ //if smaller element is present then dontd 
                continue;                   //do anything bcz its not starting el of
            }                               //subseq
            else{
                int currLen = 0;
                int curr = nums[i];
                while(s.find(curr)!=s.end()){
                    currLen++;
                    curr++;
                }
                longLen = max(longLen, currLen);
            }
        }
        return longLen;
    }
};