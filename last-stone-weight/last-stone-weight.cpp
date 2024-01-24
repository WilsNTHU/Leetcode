class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = 0;
        priority_queue<int> pq;
        for(auto &x: stones){
            pq.push(x);
            len++;
        } 
        
        while(len > 1){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if(x != y) {
                pq.push(y-x);
                len--;
            }
            else len -= 2;
        }
        
        if(pq.empty()) return 0;
        else return pq.top();
        
    }
};