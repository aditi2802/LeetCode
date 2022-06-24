class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq(target.begin(),target.end());
        for(int i=0;i<target.size();i++){
            sum += target[i];
        }
        
        while(pq.top()!=1){
            sum -= pq.top();
            
            if(sum>=pq.top() || sum<=0) return false;
            
            int prev = pq.top()%sum;
            if(sum!=1 && prev==0) return false;
            pq.pop();
            pq.push(prev);
            
            sum += prev;
        }
        return true;
    }
};