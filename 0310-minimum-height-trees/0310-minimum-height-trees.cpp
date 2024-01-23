class Solution {
public: 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0, 1};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            degree[v[0]]++;
            degree[v[1]]++;
        } 
        
        
        int node_count = n;
        vector<int> cur;
        for(int i=0; i<n; i++){
            if(degree[i] == 1){
                cur.push_back(i);
                degree[i] = 0;
            } 
        }
       
        while(node_count > 2){
            vector<int> temp;
            int len = 0;
            for(auto &leaf: cur){
                len++;
                for(auto &adj_node: adj[leaf]){
                    if(--degree[adj_node] == 1){
                        temp.push_back(adj_node);
                    }
                }
            }
            
            node_count -= len;
            cur = temp;
        }
    
        return cur;
    }
};