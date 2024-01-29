class Solution {
public:
    int helper(vector<int>& prices, vector<vector<int>> &dp, 
               int fee, int i, int holding){
        if(i >= prices.size()) return 0;
        if(dp[i][holding] != -1) return dp[i][holding];
        
        if(holding){
            int toSell = prices[i] - fee + helper(prices, dp, fee, i+1, 1-holding);
            int doNothing = helper(prices, dp, fee, i+1, holding);
            dp[i][holding] = max(toSell, doNothing);
        }
        else{
            int toBuy = -prices[i] + helper(prices, dp, fee, i+1, 1-holding);
            int doNothing = helper(prices, dp, fee, i+1, holding);
            dp[i][holding] = max(toBuy, doNothing);
        }
        
        return dp[i][holding];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return helper(prices, dp, fee, 0, 0);
    }
};