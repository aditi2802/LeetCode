class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int,int>>>q;
        vector<int> price(n,1e9);
        q.push({0,{src,0}});
        price[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops>k) continue;
            
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int nextCost = iter.second;
                if(cost+nextCost<price[adjNode]){
                    price[adjNode] = cost+nextCost;
                    q.push({stops+1, {adjNode, cost+nextCost}});
                }
            }
        }
        if(price[dst]==1e9) return -1;
        return price[dst];
    }
};