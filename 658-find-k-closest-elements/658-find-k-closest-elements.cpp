class Solution {
public:
    int abs(int a){
        if(a < 0)
            return -a;
        else 
            return a;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        pair <int,int> p;
        
        priority_queue <pair<int,int>> maxHeap;
         
        // Pushing all into the maxHeap
        // Will be sorted based on the first int of pair
        for(int i = 0; i <arr.size(); i++) {
            p = {abs(x-arr[i]),arr[i]};
            maxHeap.push(p);
        }
        
        // Removing the excess elements
        while(maxHeap.size() != k) 
            maxHeap.pop();
        
        // Removing the wanted elements and storing them into a vector
        vector <int> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};