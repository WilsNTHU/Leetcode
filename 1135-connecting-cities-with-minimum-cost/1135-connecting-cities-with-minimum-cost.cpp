class Disjoint{
    public:
        Disjoint(int size): rank(size), root(size), count(size){
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
            if(rootX != rootY){
                if(rank[rootX] < rank[rootY]) root[rootX] = rootY;
                else if(rank[rootX] > rank[rootY]) root[rootY] = rootX;
                else {
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            }
            count--;
        }
    
        bool connected(int x, int y){
            return find(x) == find(y);
        }
    
        int getCount(){
            return count;
        }
    
    private:
        vector<int> root, rank;
        int count;
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int ans = 0;
        
        sort(connections.begin(), connections.end(), 
             [](const vector<int> &v1, const vector<int> &v2){
                 return v1[2] < v2[2];
             });
        
        for(auto &t: connections){
            int u=t[0]-1, v=t[1]-1, cost=t[2];
            if(ds.find(u) != ds.find(v)){
                ds.unionSet(u, v);
                ans += cost;
            }
        }
        
        if(ds.getCount() != 1) return -1;
        else return ans;
        
    }
};