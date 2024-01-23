class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<>> pq;
        pq.push({0, 0});
        
        int dir_x[4] = {0, 1, 0, -1};
        int dir_y[4] = {1, 0, -1, 0};
        
        while(!pq.empty()){
            auto [x, y] = pq.top(); pq.pop();
            for(int i=0; i<4; i++){
                int new_x = x + dir_x[i];
                int new_y = y + dir_y[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    int new_cost = max(dist[x][y], 
                                       abs(heights[x][y]-heights[new_x][new_y]));
                    if(dist[new_x][new_y] > new_cost){
                        dist[new_x][new_y] = new_cost;
                        pq.push({new_x, new_y});
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};