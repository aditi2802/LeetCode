class DisjointSet{
public:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n){  
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i; 
        }
    }
    
    int findUPar(int node){
        if(parent[node]==node) return node; 
        return parent[node] = findUPar(parent[node]);  
    }
    
    void unionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return; 
        
        if(rank[pu]<rank[pv]) parent[pu] = pv;
        else if(rank[pv]<rank[pu]) parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    
    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;
        
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        int countC = 0;
        
        for(auto it :connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v)) extraEdges++;
            else ds.unionBySize(u,v);
        }
        
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) countC++;
        }
        int ans = countC-1;
        if(extraEdges>=ans) return ans;
        
        return -1;
    }
};