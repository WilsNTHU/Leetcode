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
                if(rank[rootX] < rank[rootY]) root[rootX] = rootY;
                else if(rank[rootX] > rank[rootY]) root[rootY] = rootX;
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
    
        int getCount(){
            return count;
        }
    
    private:
        vector<int> root, rank;
        int count;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        Disjoint s(n);
        sort(logs.begin(), logs.end(), [](const vector<int> &l, const vector<int> &r){
            return l[0] < r[0];
        });
        
        for(auto &it: logs){        
            s.unionSet(it[1], it[2]);
            if(s.getCount() == 1) return it[0];
        }
        
        return -1;
    }
};