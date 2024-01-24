class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k; i++) 
            pq.push({count(mat[i].begin(), mat[i].end(), 1), i}); 
        for(int i=k; i<mat.size(); i++){
            int val = count(mat[i].begin(), mat[i].end(), 1);
            auto [cost, num] = pq.top();
            if(val < cost){
                pq.pop();
                pq.push({val, i});
            }
        }
        
        vector<pair<int, int>> temp;
        for(int i=0; i<k; i++){
            temp.push_back(pq.top());
            pq.pop();
        }
        
        sort(temp.begin(), temp.end(), [](pair<int, int> &p1, pair<int, int> &p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
            
        vector<int> ans;
        for(auto &p: temp) ans.push_back(p.second);
        return ans;
    }
};