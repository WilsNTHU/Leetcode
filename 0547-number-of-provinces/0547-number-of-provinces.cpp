class UnionFind{
    public:
        UnionFind(int size): root(size), rank(size), count(size){
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
        vector<int> root;
        vector<int> rank;
        int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int answer = n;
        UnionFind s(n);
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j])
                    s.unionSet(i, j);
            }
        
        return s.getCount();
    }
};