class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        return NQueens_util(vis, 0, n);
    }
    
    int NQueens_util(vector<vector<bool>> &vis, int row, int n){
        int ans = 0;
        for(int col=0; col<n; col++){
            if(isSafe(vis, row, col, n)){
                if(row == n-1) ans++;
                else {
                    vis[row][col] = true;
                    ans += NQueens_util(vis, row+1, n);
                }
                vis[row][col] = false;
            }
        }
        
        return ans;
    }
    
    bool isSafe(vector<vector<bool>> &vis, int &row, int &col, int &n){
        
        // examine the upper half of the same column
        for(int i=row-1; i>=0; i--){
            if(vis[i][col]) return false;
        }
        
        // examine the upper left half of the diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(vis[i][j]) return false;
        }
        
        // examine the upper right half of the diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(vis[i][j]) return false;
        }
        
        return true;
    }
    
};