class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        
        vector<vector<int>> adj(numCourses);
        vector<int> in_deg(numCourses, 0);
        for(auto &x: prerequisites){
            adj[x[1]].push_back(x[0]);
            in_deg[x[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(in_deg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int num = q.front(); q.pop();
            result.push_back(num);
            
            for(auto &x: adj[num]){
                if(--in_deg[x] == 0){
                    q.push(x);
                }
            }
        }
        
        vector<int> temp;
        if(result.size() != numCourses) return temp;
        else return result;
    }
};