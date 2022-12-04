class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum=0;
        for(auto i:nums)   sum+=i;
        long long n=nums.size(),i=0,first=0,average=INT_MAX ,new_average;
        int ans;
        while(i<n){
            first=(first+nums[i]);
           long long first_av=first/(i+1);
            if (i==n-1) 
                new_average=first_av;
            else
               new_average=abs(first_av-(sum-first)/(n-i-1)) ;
            
            if(new_average <average){ 
                ans=i;
            }
            else {
                i++;continue;             
             }
            average=new_average;
            i++;
        }
        return ans;
    }
};