class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n));
        vector<vector<int>> dis(m, vector<int>(n));
        queue<tuple<int, int, int>> q;
        
        int dir_x[] = {0, 1, 0, -1};
        int dir_y[] = {1, 0, -1, 0};
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(!mat[i][j]){
                    q.push(make_tuple(i, j, 0));
                    vis[i][j] = 1;
                }
            }
        
        while(!q.empty()){
            int x, y, dist;
            tie(x, y, dist) = q.front(); q.pop();
            dis[x][y] = dist;
            for(int i=0; i<4; i++){
                int new_x = x + dir_x[i];
                int new_y = y + dir_y[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && !vis[new_x][new_y])                 {
                    q.push(make_tuple(new_x, new_y, dist+1));
                    vis[new_x][new_y] = 1;
                }
            }
        }
        
        return dis;
    }
};