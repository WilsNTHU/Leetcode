class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto &it: nums){
            if(freq[it] == 0) freq[it] = 1;
            else freq[it]++;
        }
        
        int size = 0;
        auto bigger = [&](int x, int y){return freq[x] > freq[y];};
        priority_queue<int, vector<int>, decltype(bigger)> pq(bigger);
        for(auto &[key, val]: freq){
            pq.push(key);
            size++;
            if(size > k){
                size--;
                pq.pop();
            }
        }
        
        vector<int> ans(k);
        reverse_copy(&(pq.top()), &(pq.top())+k, ans.begin());
        
        return ans;
    }
};