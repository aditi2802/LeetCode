class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& graph){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, graph)==true) return true;
            }
            else if(vis[it] && pathvis[it]) return true;
        }
        pathvis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathvis(v, 0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, graph);
            }
        }
        
        for(int i=0;i<v;i++){
            if(pathvis[i]==0) ans.push_back(i);
        }
        
        return ans;
    }
};