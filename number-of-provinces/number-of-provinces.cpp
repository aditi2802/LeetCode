class DisjointSet{
    vector<int> rank;
    vector<int> size;
    vector<int> parent;
public:
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);
        int count = 0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1) ds.unionBySize(i,j);
            }
        }
        for(int i=0;i<V;i++){
            if(ds.findUPar(i)==i) count++;
        }
        return count;
    }
};