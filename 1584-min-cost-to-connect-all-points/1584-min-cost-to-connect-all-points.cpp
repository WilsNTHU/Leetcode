class Edge{
    public:
        int p1, p2, cost;
        Edge(int _p1, int _p2, int _cost): p1(_p1), p2(_p2), cost(_cost){}
};

bool operator<(const Edge& e1, const Edge &e2){
    return e1.cost > e2.cost;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // min_heap
        priority_queue<Edge> pq;
        vector<bool> vis(n, false);
        int count = 0;
        int ans = 0;
        
        for(int i=1; i<n; i++){
            int cost = abs(points[i][0]-points[0][0]) + 
                       abs(points[i][1]-points[0][1]);
            pq.push(Edge(0, i, cost));
        }
        
        vis[0] = true;
        while(!pq.empty() && count!=n-1){
            Edge e = pq.top(); pq.pop();
            int pt = e.p2;
            if(!vis[pt]){
                vis[pt] = true;
                ans += e.cost;
                for(int i=0; i<n; i++){
                    if(!vis[i]){
                        int cost = abs(points[i][0]-points[pt][0]) + 
                           abs(points[i][1]-points[pt][1]);
                        pq.push(Edge(pt, i, cost));
                    }
                }
                count++;
            }
            
        }
        
        return ans;
    }
};