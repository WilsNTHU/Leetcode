class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int offset[5] = {0, 1, 0, -1, 0};
        
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '1'){
                    count++;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    grid[i][j] = '0';
                    while(q.size() != 0){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int x = p.first + offset[k];
                            int y = p.second + offset[k+1];
                            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1'){
                                grid[x][y] = '0';
                                q.emplace(x, y);
                            }      
                        }
                    }
                }
        
        return count;
    }
    
};