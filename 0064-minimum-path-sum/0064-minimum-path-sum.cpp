class Solution {
public:
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        if(i==(m-1) && j==(n-1)) return grid[i][j];
        
        int right_sum = INT_MAX, down_sum = INT_MAX;
        if(i < (m-1)) down_sum = helper(grid, dp, i+1, j);
        if(j < (n-1)) right_sum = helper(grid, dp, i, j+1);
        
        return dp[i][j] = grid[i][j] + min(down_sum, right_sum);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, dp, 0, 0);
    }
};