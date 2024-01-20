class Disjoint{
    public:
        Disjoint(int size): root(size), rank(size), count(size){
            this->size = size;
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
    
        string getResult(string &str){
            unordered_map<int, vector<int>> child;
            for(int i=0; i<size; i++){
                child[find(i)].push_back(i);
            }
            
            string ans;
            ans.resize(size);
            
            for(auto &p: child){
                string temp = "";

                for(auto &x: p.second) temp += str[x];
                sort(temp.begin(), temp.end());
                int k = 0;
                for(auto &x: p.second){
                    ans[x] = temp[k++];
                }
            }
            return ans;
        }
    
    private:
        vector<int> rank, root;
        int count;
        int size;
};

class Solution {
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        Disjoint ds(n);
        
        for(auto &p: pairs) ds.unionSet(p[0], p[1]);
        return ds.getResult(s);
    }
};