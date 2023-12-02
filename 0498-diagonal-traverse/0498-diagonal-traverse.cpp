class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> answer;
        
        int x = 0;
        int sum = 0;
        int dir = -1;
        
        auto addToAnswer = [&](){
            int y = sum - x;
            answer.push_back(mat[x][y]);
        };
        
        auto ok = [&](int x){
            int y = sum - x;
            return (x>=0) && (y>=0) && (x<m) && (y<n);
        };
        
        addToAnswer();
        
        while(sum != (m-1) + (n-1)){
            sum ++;
            
            // when moving upwards(dir==-1), only increment x after hitting the diagonal line
            // when moving downwards(dir==+1), only increment x before hitting the diagonal line
            
            if((dir == -1 && !ok(x)) || (dir == 1 && ok(x+1))) x++;
            addToAnswer();
            
            dir = -dir;
            
            while(ok(x+dir)){
                x += dir;
                addToAnswer();
            }
        }
        
        return answer;
    }
};