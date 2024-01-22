class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        
        for(auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        stack<int> st;
        st.push(source);
        
        while(!st.empty()){
            int node = st.top(); st.pop();
            if(node == destination) return true;
            if(vis[node]) continue;
            
            vis[node] = true;
            for(auto &x: adj[node]) st.push(x);
            
        }
        
        return false;
    }
};