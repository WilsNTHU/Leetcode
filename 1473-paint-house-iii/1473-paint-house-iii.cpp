class Solution {
public:
    int M, N, T;
    vector<int> H;
    vector<vector<int>> C;
    vector<vector<vector<int>>> dp;
    
    int helper(int i, int j, int sum){
        if(sum > T) return 1e9;
        if(i>=M) return (sum == T) ? 0 : 1e9;
        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        if(H[i] != 0)
            return dp[i][j][sum] = helper(i+1, H[i], H[i]==j ? sum : sum+1);
        
        int min_val = 1e9;
        for(int color=1; color<=N; color++)
            min_val = min(min_val, C[i][color-1] + helper(i+1, color, 
                                                          color==j ? sum : sum+1));
        
        return dp[i][j][sum] = min_val;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, 
                int m, int n, int target) {
        M = m, N = n;
        T = target;
        H = houses, C = cost;
        dp.assign(m, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        int ans = helper(0, 0, 0);
        return ans == 1e9 ? -1 : ans;
    }
};