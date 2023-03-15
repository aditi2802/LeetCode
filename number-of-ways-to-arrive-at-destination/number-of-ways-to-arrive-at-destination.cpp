class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> price(n, LONG_MAX);
        vector<long long> ways(n, 0);
        price[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (long long)(1e9+7);
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long cost = it.first;
            long long node = it.second;
            
            for(auto iter : adj[node]){
                long long adjNode = iter.first;
                long long nextCost = iter.second;
                
                if(cost+nextCost<price[adjNode]){
                    price[adjNode] = cost+nextCost;
                    ways[adjNode] = ways[node];
                    pq.push({cost+nextCost, adjNode});
                }
                else if(cost+nextCost==price[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};