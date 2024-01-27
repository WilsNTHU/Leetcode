class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        // dp[0] = dp[1] = 0;
        int one_back = 0, two_back = 0;
        for(int i=2; i<=n; i++){
            int temp = one_back;
            one_back = min(one_back+cost[i-1], two_back+cost[i-2]);
            two_back = temp;
        } 
        
        // for(int i=2; i<=n; i++) dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        
        // return dp[n];
        return one_back;
    }
    
};