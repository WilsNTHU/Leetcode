class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>> &dp, int amount, int idx){
        if(idx < 0) return 0;
        if(amount == 0) return 1;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int take = 0, notTake = 0;
        if(amount >= coins[idx]) take = helper(coins, dp, amount-coins[idx], idx);
        notTake = helper(coins, dp, amount, idx-1);
        
        return dp[idx][amount] = (take + notTake);
        
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = helper(coins, dp, amount, n-1);
        return ans;
    }
};