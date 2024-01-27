class Solution {
public:
    int helper(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int j, int hold){
        if(i==prices.size() || j==0) return 0;
        if(dp[i][j][hold] != -1) return dp[i][j][hold];
        if(hold == 1) 
            dp[i][j][hold] = max(prices[i] + helper(prices, dp, i+1, j-1, 1-hold)
                                , helper(prices, dp, i+1, j, hold));
        else 
            dp[i][j][hold] = max(-prices[i] + helper(prices, dp, i+1, j, 1-hold)
                                            , helper(prices, dp, i+1, j, hold));
        
        return dp[i][j][hold];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        
        for(int i=n-1; i>=0; i--)
            for(int j=1;j<=k; j++)
                for(int hold=0; hold<2; hold++){
                    if(hold == 1)
                        dp[i][j][hold] = max(prices[i] + dp[i+1][j-1][1-hold]
                                , dp[i+1][j][hold]);
                    else 
                        dp[i][j][hold] = max(-prices[i] + dp[i+1][j][1-hold]
                                , dp[i+1][j][hold]);
                }
        
        return dp[0][k][0];
        
        // return helper(prices, dp, 0, k, 0);
        
    }
};