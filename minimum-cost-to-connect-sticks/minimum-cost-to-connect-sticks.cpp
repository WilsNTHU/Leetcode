class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int len = 0, ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto &x: sticks){
            pq.push(x);
            len++;
        }
            
        while(len > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            ans += (x+y);
            pq.push(x+y);
            len--;
        }
        
        return ans;
    }
};