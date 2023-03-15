//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long, long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> price(n, 1e18);
        vector<long long> ways(n, 0);
        price[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (long long)(1e9+7);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long cost = it.first;
            long long node = it.second;
            
            for(auto iter: adj[node]){
                long long adjNode = iter.first;
                long long nextCost = iter.second;
                
                if(cost+nextCost<price[adjNode]){
                    price[adjNode] = cost+nextCost;
                    pq.push({cost+nextCost, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(cost+nextCost==price[adjNode]){
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends