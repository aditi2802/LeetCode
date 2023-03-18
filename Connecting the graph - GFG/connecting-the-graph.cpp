//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int countC = 0;
        int extraEdges = 0;
        DisjointSet ds(n);
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) extraEdges++;
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends