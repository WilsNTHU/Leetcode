class Solution {
public:
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i>=m || j>=n) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(i==(m-1) && j==(n-1)) return grid[i][j];
        
        int right_sum = helper(grid, dp, i, j+1);
        int down_sum = helper(grid, dp, i+1, j);
        
        return dp[i][j] = grid[i][j] + min(down_sum, right_sum);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, dp, 0, 0);
    }
};