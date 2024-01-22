class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int count = -1;
        int count_fresh = 0;
        
        int dir_x[4] = {0, 1, 0, -1};
        int dir_y[4] = {1, 0, -1, 0};
  
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                    q.emplace(i, j);
                if(grid[i][j] == 1)
                    count_fresh++;
            }
        
        if(!count_fresh) return 0;

        
        while(!q.empty()){
            count++;
            for(int i=q.size(); i>0; i--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++){
                    int new_x = x + dir_x[k];
                    int new_y = y + dir_y[k];
                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n
                      && grid[new_x][new_y]==1){
                        q.emplace(new_x, new_y);
                        grid[new_x][new_y] = 2;
                        count_fresh--;
                    }
                }
            }
        }
        
        if(count_fresh) return -1;
        return count;

    }
};