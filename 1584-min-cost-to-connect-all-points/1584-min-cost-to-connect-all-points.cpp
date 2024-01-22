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
        vector<tuple<int, int, int>> edges;
        Disjoint ds(n);
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                int dis = abs(points[i][0]-points[j][0]) 
                         + abs(points[i][1]-points[j][1]);
                edges.emplace_back(i, j, dis);
            }
        
        sort(edges.begin(), edges.end(), 
             [](tuple<int, int, int> &t1, tuple<int, int, int> &t2){
                 int p1, p2, p3, p4, dis1, dis2;
                 tie(p1, p1, dis1) = t1;
                 tie(p3, p4, dis2) = t2;
                 return dis1 < dis2;
             });
        
        int ans = 0;
        int edge_count = 0;
        
        for(auto &t: edges){
            if(edge_count == n-1) return ans; 
            
            int p1, p2, dis;
            tie(p1, p2, dis) = t;
            if(ds.find(p1) != ds.find(p2)){
                ds.unionSet(p1,p2);
                ans += dis;
                edge_count++;
            }
        }
        
        return ans;
    }
};