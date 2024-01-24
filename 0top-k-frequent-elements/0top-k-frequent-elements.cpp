class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto &x: nums) freq[x]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto &p: freq) 
            pq.push({p.second, p.first});
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            auto [cost, num] = pq.top(); pq.pop();
            ans.push_back(num);
        }
        
        return ans;
    }
};