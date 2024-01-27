class Solution {
public:
    int helper(vector<int>& prices, vector<vector<int>> &dp, int i, int stockCount){
        if(i>= prices.size() || stockCount>=prices.size()) return 0;
        if(dp[i][stockCount] != -1) return dp[i][stockCount];
        if(stockCount>0) 
            dp[i][stockCount] = max(prices[i]+helper(prices, dp, i+2, stockCount-1), 
                            max(-prices[i] + helper(prices, dp, i+1, stockCount-1), 
                                    helper(prices, dp, i+1, stockCount))
                                   );
        else{
            dp[i][stockCount] = max(-prices[i] + helper(prices, dp, i+1, stockCount+1), helper(prices, dp, i+1, stockCount));
        }
        
        return dp[i][stockCount];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(prices, dp, 0, 0);
    }
};