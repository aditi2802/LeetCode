class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int i = 0;
        int j = numbers.size()-1;
        
        while(i<j){
            int curr = numbers[i]+numbers[j];
            
            if(curr==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(curr<target){
                i++;
                
            }
            else{
                j--;
                
            }
        }
        return v;
    }
};