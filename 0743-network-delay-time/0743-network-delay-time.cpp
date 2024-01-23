class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, 1e9);
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &v: times)
            adj[v[0]-1].push_back({v[1]-1, v[2]});
        
        
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.first > p2.first;
        };
        
        // pair<int, int> -> (cost, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>               pq(cmp);
        pq.push({0, k-1});
        dis[k-1] = 0;
        
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &v: adj[node]){
                int n2 = v.first;
                int c2 = v.second;
                if(cost + c2 < dis[n2]){
                    dis[n2] = cost + c2;
                    pq.push({dis[n2], n2});
                }
            }
        }
        
        if(find(dis.begin(), dis.end(), 1e9) != dis.end()) return -1;
        else return *max_element(dis.begin(), dis.end());
    }
};