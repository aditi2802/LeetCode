class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int v = graph.size();
        vector<int> color(v, -1);
        
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                q.push(i);
                color[i] = 0;
            }
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto it : graph[node]){
                    if(color[it]==-1){
                        q.push(it);
                        color[it] = !color[node];
                    }
                    else{
                        if(color[it]==color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};