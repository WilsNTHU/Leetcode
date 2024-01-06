class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        for(auto &it: rooms[0]){
            q.push(it);
            vis[it] = true;
        }
        vis[0] = true;
        
        while(!q.empty()){
            int key = q.front();
            q.pop();
            for(auto &it: rooms[key]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        
        for(auto it: vis) if(!it) return false;
        return true;
        
    }
};