class Solution {
public:
    
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(dp, n);
    }
    
    int helper(vector<int> &dp, int n){
        if(dp[n] != -1) return dp[n];
        else{
            if(n <= 1) return n;
            else return helper(dp, n-1) + helper(dp, n-2);
        }
    }
    
};