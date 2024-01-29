#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Top-down Memoization, TLE
// class Solution {
// public:
//     int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, 
//             int n, int i, int j){
//         if(j<0 || j>=n) return INT_MAX;
//         if(i == n-1) return matrix[i][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down_sum = dfs(matrix, dp, n, i+1, j);
//         int down_left_sum = dfs(matrix, dp, n, i+1, j-1);
//         int down_right_sum = dfs(matrix, dp, n, i+1, j+1);
        
//         return dp[i][j] = matrix[i][j] + min(down_sum, 
//                                              min(down_left_sum, down_right_sum));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
          
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int min_val = INT_MAX;
//         for(int j=0; j<n; j++)
//             min_val = min(min_val, dfs(matrix, dp, n, 0, j));
        
//         return min_val;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
          
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for(int j=0; j<n; j++) dp[0][j] = matrix[0][j];

        for(int i=1; i<n; i++)
            for(int j=0; j<n; j++){
                int up = dp[i-1][j];
                int up_left = INT_MAX, up_right = INT_MAX;
                if(j>0) up_left = dp[i-1][j-1];
                if(j<n-1) up_right = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min(up, min(up_left, up_right));
            }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};