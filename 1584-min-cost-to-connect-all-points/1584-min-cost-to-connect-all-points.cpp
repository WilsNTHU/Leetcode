class Edge {
    public:
        int p1, p2, cost;
        Edge(int _p1, int _p2, int _cost): p1(_p1), p2(_p2), cost(_cost){}
};

class Disjoint {
    public:
        Disjoint(int size): root(size), rank(size), count(size){
            for(int i=0; i<size; i++){
                root[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x){
            if(x == root[x]) return x;
            return root[x] = find(root[x]);
        }

        void unionSet(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            
            if(rank[rootX] < rank[rootY]) root[rootX] = rootY;
            else if(rank[rootX] > rank[rootY]) root[rootY] = rootX;
            else{
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }

        bool connected(int x, int y){
            return find(x) == find(y);
        }
    
    private:
        vector<int> rank, root;
        int count;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        Disjoint ds(n);
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                int dis = abs(points[i][0]-points[j][0]) 
                         + abs(points[i][1]-points[j][1]);
                edges.emplace_back(i, j, dis);
            }
        
        sort(edges.begin(), edges.end(), 
             [](const Edge &e1, const Edge &e2){
                 return e1.cost < e2.cost;
             });
        
        int ans = 0;
        int edge_count = 0;
        
        for(auto &e: edges){
            if(edge_count == n-1) return ans; 
            
            if(ds.find(e.p1) != ds.find(e.p2)){
                ds.unionSet(e.p1,e.p2);
                ans += e.cost;
                edge_count++;
            }
        }
        
        return ans;
    }
};