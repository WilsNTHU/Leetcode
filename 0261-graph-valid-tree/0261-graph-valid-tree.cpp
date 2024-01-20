class Disjoint{
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
            
            if(rootX != rootY){
                if(rank[rootX] < rank[rootY]){
                    root[rootX] = rootY;
                }
                else if(rank[rootX] > rank[rootY]){
                    root[rootY] = rootX;
                }
                else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
                count--;
            }
        }
    
        bool connected(int x, int y){
            return find(x) == find(y);
        }
    
        int getCount(){return count;}
    
    private:
        vector<int> root, rank;
        int count;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        Disjoint s(n);
        for(auto &it: edges){
            if(s.connected(it[0], it[1])) return false;
            else s.unionSet(it[0], it[1]);
        }
        return s.getCount() == 1;
    }
};