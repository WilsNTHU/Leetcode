class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return helper(dp, n);
    }
    
    int helper(vector<int> &dp, int n){
        if(n <= 2) return n;
        if(dp[n]) return dp[n];
        else return dp[n] = helper(dp, n-1) + helper(dp, n-2);
    }
};