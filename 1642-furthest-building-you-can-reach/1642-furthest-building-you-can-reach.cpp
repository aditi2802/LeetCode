class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int i = 0;
        int diff = 0;
        for(;i<heights.size()-1;i++){
            diff = heights[i+1]-heights[i];
            
            if(diff<=0) continue;
            
            bricks -= diff;
            q.push(diff);
            
            if(bricks<0){
                bricks += q.top();
                q.pop();
                ladders--;
            }
            
            if(ladders<0) break;
        }
        return i;
    }
};