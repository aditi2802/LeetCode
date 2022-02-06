class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
           return n;
        }
        
        int count = 1;
        int j = 1;                   //We use pointer i to iterate over the array and     
        for(int i=1;i<n;i++){        //j to iterate over the modified array.
          if(nums[i]==nums[i-1]){
             count++;
          }
            else{
              count = 1;
            }
            
            if(count<=2){
               nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};