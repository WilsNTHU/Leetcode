class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto &v: relations){
            adj[v[0]-1].push_back(v[1]-1);
            indegree[v[1]-1]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegree[i] == 0) q.push(i);
        
        int semester = 0;
        if(q.empty()) return -1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int node = q.front(); q.pop();
                for(auto &x: adj[node]){
                    if(--indegree[x] == 0) q.push(x);
                }
            }
            semester++;
        }
        
        for(auto &x: indegree)
            if(x != 0) return -1;
        
        return semester;
    }
};