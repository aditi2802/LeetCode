class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
        }
        
        while(minHeap.size()!=0){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};