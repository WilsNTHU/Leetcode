class Solution {
public:
    
    int helper(vector<vector<char>> &matrix, vector<vector<int>> &dp, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(matrix[i][j] == '0') return 0;

        int up = helper(matrix, dp, i-1, j);
        int left = helper(matrix, dp, i, j-1);
        int diagonal = helper(matrix, dp, i-1, j-1);
        
        dp[i][j] = min(up, min(left, diagonal)) + 1;
        
        return dp[i][j];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MIN;
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
                ans = max(ans, helper(matrix, dp, i, j));
        
        return ans * ans;
    }
};