#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        
        // for(int i=0; i<m; i++)
        //     for(int j=0; j<n; j++){
        //         if(i-1>=0) 
        //             dp[i][j] += dp[i-1][j];
                
        //         if(j-1>=0) 
        //             dp[i][j] += dp[i][j-1];
        //     }

        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                int sum = 0;
                sum += dp[i-1][j];
                sum += dp[i][j-1];
                dp[i][j] = sum;
            }
        
        return dp[m-1][n-1];
    }
};