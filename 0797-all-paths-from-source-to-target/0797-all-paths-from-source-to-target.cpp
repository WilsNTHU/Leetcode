class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, int &n, vector<int>& path, vector<vector<int>>& paths){
        path.push_back(node);
        if(node == n-1){
            paths.emplace_back(path);
            return;
        }
        
        for(auto &x: graph[node]){
            dfs(graph, x, n, path, paths);
            path.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> paths;
        dfs(graph, 0, n, path, paths);
        return paths;
    }
};