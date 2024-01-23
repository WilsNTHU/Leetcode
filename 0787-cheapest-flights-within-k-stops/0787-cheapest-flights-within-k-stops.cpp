class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &t: flights) graph[t[0]].push_back({t[1], t[2]});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        
        queue<tuple<int, int, int>> q; // (cost, node, edge_count)
        q.push({0, src, 0});
        
        while(!q.empty()){
            auto [cost, node, edge_count] = q.front(); q.pop();
            if(edge_count >= k+1) continue;
        
            for(auto &p: graph[node]){
                int adjNode = p.first, weight = p.second;
                if(cost + weight < dist[adjNode] && edge_count<=k){
                    dist[adjNode] = cost + weight;
                    q.push({dist[adjNode], adjNode, edge_count+1});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        else return dist[dst];
    }
};