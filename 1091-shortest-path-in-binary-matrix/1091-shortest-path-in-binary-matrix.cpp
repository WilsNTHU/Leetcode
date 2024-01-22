class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        int ans = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vis[0][0] = true;
        
        int dir_x[8] = {0, 1, 0, -1, -1, 1, -1, 1};
        int dir_y[8] = {1, 0, -1, 0, 1, 1, -1, -1};
        
        while(!q.empty()){
            ans++;
            
            for(int i=q.size(); i>0; i--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x==n-1 && y==n-1) return ans;
                
                for(int i=0; i<8; i++){
                    int new_x = x + dir_x[i];
                    int new_y = y + dir_y[i];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n &&
                       !grid[new_x][new_y] && !vis[new_x][new_y]){
                        q.emplace(new_x, new_y);
                        vis[new_x][new_y] = true;
                    }
                }
            }
            
        }
        
        return -1;
    }
};