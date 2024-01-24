class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>> pq;
        for(int i=0; i<k; i++){
            int val = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({val, points[i][0], points[i][1]});
        }
        
        auto[cost, x, y] = pq.top();
        for(int i=k ;i<points.size(); i++){
            int val = pow(points[i][0],2) + pow(points[i][1],2);
            if(val < cost){
                pq.push({val, points[i][0], points[i][1]});
                pq.pop();
                tie(cost, x, y) = pq.top();
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            auto[cost, x, y] = pq.top();
            ans.push_back({x, y});
            pq.pop();
        }
        
        return ans;
    }
};