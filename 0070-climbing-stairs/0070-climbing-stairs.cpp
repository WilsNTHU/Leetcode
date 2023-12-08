class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(dp, n);
    }
    
    int helper(vector<int> &dp, int n){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        else return dp[n] = helper(dp, n-1) + helper(dp, n-2);
    }
};