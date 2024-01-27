class Solution {
public:
    int helper(vector<int> &dp, int k, int i){
        if(i == 1) return k;
        if(i == 2) return k*k;
        dp[i] = helper(dp, k, i-1) * (k-1) + helper(dp, k, i-2) * (k-1);
        return dp[i];
        
    }
    
    int numWays(int n, int k) {
        // vector<int> dp(n+1, -1);
        if(n == 1) return k;
        if(n == 2) return k*k;
        
        
        vector<int> dp(n+1, 0);
        dp[1] = k;
        dp[2] = k*k;
        for(int i=3; i<=n; i++) 
            dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
        return dp[n];
        // return helper(dp, k, n);
    }
};
