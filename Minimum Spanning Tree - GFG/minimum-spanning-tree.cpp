//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //kruskal's algo
        int mstWt = 0;
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node,adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends