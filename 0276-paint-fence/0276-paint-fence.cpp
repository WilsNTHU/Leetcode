class Solution {
public:
    int helper(vector<int> &dp, int k, int i){
        if(i == 1) return k;
        if(i == 2) return k*k;
        dp[i] = helper(dp, k, i-1) * (k-1) + helper(dp, k, i-2) * (k-1);
        return dp[i];
        
    }
    
    int numWays(int n, int k) {
        vector<int> dp(n+1, -1);
        return helper(dp, k, n);
    }
};
