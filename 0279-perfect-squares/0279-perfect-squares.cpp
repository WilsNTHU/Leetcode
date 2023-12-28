class Solution {
public:
    int numSquares(int n) {
        if(n <= 2) return n;
        
        unordered_set<int> visited;
        
        int steps = 0;
        queue<int> q;
        q.push(n);
        visited.insert(n);
        
        for(; !q.empty(); steps++){
            for(int i=q.size(); i>0; i--){
                int num = q.front();
                q.pop();
                if(num == 0) return steps;
                for(int i=1; i*i <= n; i++){
                    int temp = num - (i*i);
                    if(temp == 0) return steps+1;
                    else if(temp>0 && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    } 
                }
            }
        }
        
        return steps; // NOT REACHED
    }
};