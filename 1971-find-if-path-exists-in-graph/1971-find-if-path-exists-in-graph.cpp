class Solution {
private:
    bool dfs(int s, int e, vector<vector<int>>& adj, vector<int>& vis){
        if(s==e) return true;
        if(vis[s]) return false;
        
        vis[s] = 1;
        for(int i=0;i<adj[s].size();i++){
            if(dfs(adj[s][i], e, adj, vis)) return true;
        }
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){             //making adj list
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        return dfs(start, end, adj, vis);
    }
};