class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        
        for(auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        q.push(source);
        vis[source] = true;
        
        while(!q.empty()){
            int num = q.front(); q.pop();
            if(num == destination) return true;
            
            for(auto &x: adj[num]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        
        return false;
    }
};