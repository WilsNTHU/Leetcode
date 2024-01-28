// Bottom Up Dp Solution
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         if(m==1 && n==1) return !obstacleGrid[0][0];
        
//         dp[0][0] = 1;
//         for(int i=0; i<m; i++)
//             for(int j=0; j<n; j++){
//                 if(obstacleGrid[i][j] == 0){
//                     if(i-1>=0 && obstacleGrid[i-1][j] == 0)
//                         dp[i][j] += dp[i-1][j];
//                     if(j-1>=0 && obstacleGrid[i][j-1] == 0)
//                         dp[i][j] += dp[i][j-1];
//                 }
//             }
        
//         return dp[m-1][n-1];
//     }
// };

class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<int>> &dp, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];

        int m = grid.size(), n = grid[0].size();
        if(i==(m-1) && j==(n-1) && grid[i][j]==0) return 1;
        if(grid[i][j]==1) return 0;

        int right_sum = 0;
        if(j+1<n && grid[i][j+1] == 0) right_sum = helper(grid, dp, i, j+1);
        int down_sum = 0;
        if(i+1<m && grid[i+1][j] == 0) down_sum = helper(grid, dp, i+1, j);

        return dp[i][j] = (right_sum + down_sum);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return helper(obstacleGrid, dp, 0, 0);
    }
};