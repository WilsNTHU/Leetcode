class Solution {
public:
    int numTilings(int n) {
        if(n <= 2) return n;
        if(n == 3) return 5;
        
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        // dp[n] = 2*dp[n-1] + dp[n-3]
        long long temp;
        for(int i=4; i<=n; i++){
            temp = 0;
            temp += dp[i-1];
            temp += dp[i-1];
            temp += dp[i-3];
            dp[i] = temp % (int)(1e9 + 7);
        }
        
        return dp[n];
    }
};