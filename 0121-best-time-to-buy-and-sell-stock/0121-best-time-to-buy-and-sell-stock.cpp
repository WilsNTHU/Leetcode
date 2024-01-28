class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Below is Dynamic Programming Approach
        // vector<int> dp(n, -1);
        
        // dp[n-1] = prices[n-1];
        // for(int i=n-2; i>=0; i--) dp[i] = max(prices[i], dp[i+1]);
        
        // int ans = INT_MIN;
        // for(int i=0; i<=n-2; i++){
        //    ans = max(ans, -prices[i] + dp[i+1]);
        // }
        
        // if(ans <= 0) return 0;
        // return ans;
        
        int min_buy = INT_MAX, max_sell = 0;
        for(int i=0; i<=n-1; i++){
            min_buy = min(min_buy, prices[i]);
            max_sell = max(max_sell, prices[i]-min_buy);
        }
        
        return max_sell;
    }
};