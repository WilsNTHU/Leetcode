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
        
            
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};