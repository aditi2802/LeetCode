class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       /* int n=nums.size();
        int count=2,i,j;
        if(nums[1]-nums[0]==0)
        {
            count--;
        }
        
        
        
        
        for(i=0,j=1;i<n-2,j<n-1;i++,j++)
        {
            
            if(nums[i+1]-nums[i]>0 && nums[j+1]-nums[j]<0 || nums[i+1]-nums[i]<0 && nums[j+1]-nums[j]>0)
            {
                if(nums[i+1]-nums[i]==0||nums[j+1]-nums[j]==0)
                {
                    count--;
                }
                count++;
            }
        }
        return min(n,count);
    }*/
 int n = nums.size();
        
        if(n == 1)
            return 1;
        
        int count = 0;
        
        int prev_diff = nums[1] - nums[0];
        
        if(prev_diff == 0)
        {
            count = 1;
        }
        else
        {
            count = 2;
        }
        
        for(int i = 2; i < n; i++)
        {
            int curr_diff = nums[i] - nums[i - 1];
            
            if((prev_diff >= 0 && curr_diff < 0) || (prev_diff <= 0 && curr_diff > 0))
            {
                count++;
                
                prev_diff = curr_diff;
            }
        }
        
        return count;
    }
};