class Solution {
public:
    int helper(vector<vector<int>> &dp, int n, int &k, int target){
        if(target < 0) return 0;
        if(n == 0) return target == 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        long long temp = 0;
        for(int num=1; num<=k; num++)
            temp += helper(dp, n-1, k, target-num);
            
        
        return dp[n][target] = temp % (int)(1e9 + 7);
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(dp, n, k, target);
    }
};