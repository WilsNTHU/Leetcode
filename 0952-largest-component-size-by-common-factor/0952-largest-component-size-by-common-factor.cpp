class Disjoint{
    public:
        Disjoint(int size): root(size), rank(size, 1), count(size){
            for(int i=0; i<size; i++) root[i] = i;
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
    
    int largestComponentSize(vector<int>& nums) {
        Disjoint s(*max_element(nums.begin(), nums.end()) + 1);
        
        for(auto &x: nums){
            for(int f=2; f<=sqrt(x); f++){
                if(x%f == 0){
                    s.unionSet(x, f);
                    s.unionSet(x, x/f);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int ans = INT_MIN;
        for(auto &x: nums){
            ans = max(ans, ++mp[s.find(x)]);
        }
        
        return ans;
    }
};