class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); int n = image[0].size();
        
        int dir[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        
        
        q.emplace(sr, sc);
        int num = image[sr][sc];
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for(int i=0; i<4; i++){
                int x = p.first + dir[i];
                int y = p.second + dir[i+1];
                if(x>=0 && x<m && y>=0 && y<n && image[x][y]==num 
                   && image[x][y]!=color)
                    q.emplace(x, y);
            }
        }
        
        return image;
    }
   
};