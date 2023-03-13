//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        //make graph
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        //q stops node price
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{src,0}});
        vector<int> price(n,1e9);
        price[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>K) continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int nextCost = iter.second;
                
                if(cost+nextCost<price[adjNode] && stops<=K){
                    price[adjNode] = cost+nextCost;
                    q.push({stops+1, {adjNode, cost+nextCost}});
                }
            }
        }
        if(price[dst]==1e9) return -1;
        
        return price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends